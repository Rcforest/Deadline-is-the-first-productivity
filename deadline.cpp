#include "deadline.h"
#include "ui_deadline.h"
#include "qddler.h"


#include <QListWidget>
#include <QDialog>
#include <QtDebug>



deadline::deadline(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deadline)
{
    ui->setupUi(this);



    ddler = new Qddler;

    iniUI();
    iniconnect();
//    inilistModel();

}

deadline::~deadline()
{
    delete ui;
    delete ddler;
}

void deadline::iniUI(){  //初始化ui界面
    labWeek = new QLabel;
    labWeek -> setText("第" + QString::number(ddler->getWeek()) + "周");
    labWeek ->setAlignment(Qt::AlignCenter);
    labWeek -> setMinimumWidth(200);
    ui -> statusbar -> addWidget(labWeek);

    prbWeek = new QProgressBar;
    prbWeek -> setMaximumWidth(500);
    prbWeek ->setMinimum(0);
    prbWeek ->setMaximum(10);
    prbWeek ->setValue(ddler->getWeek());
    prbWeek ->setFormat("%v / %m");
    ui -> statusbar -> addWidget(prbWeek);

    lcdTime = new QLCDNumber;
    lcdTime -> setDigitCount(4);
    lcdTime -> display(ddler->getTime());
    QPalette lcdpatTime = lcdTime->palette();
    lcdpatTime.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
    lcdTime->setPalette(lcdpatTime);
    lcdTime->setStyleSheet("background-color: black");
    ui ->Vlaylcd->addWidget(lcdTime);

    lcdEnergy = new QLCDNumber;
    lcdEnergy ->setDigitCount(3);
    lcdEnergy ->display(ddler->getEnergy());
    QPalette lcdpatEnergy = lcdEnergy->palette();
    lcdpatEnergy.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
    lcdEnergy->setPalette(lcdpatEnergy);
    lcdEnergy->setStyleSheet("background-color: black");
    ui ->Vlaylcd->addWidget(lcdEnergy);

    lcdDdl = new QLCDNumber;
    lcdDdl ->setDigitCount(3);
    lcdDdl ->display(ddler->getDeadline());
    QPalette lcdpatDdl = lcdDdl->palette();
    lcdpatDdl.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
    lcdDdl->setPalette(lcdpatDdl);
    lcdDdl->setStyleSheet("background-color: black");
    ui ->Vlaylcd->addWidget(lcdDdl);

}


void deadline::iniconnect(){//初始化信号与槽的连接
    connect(ddler, SIGNAL(onTimechanged()),this, SLOT(refreshTime()));
    connect(ddler, SIGNAL(onEnergychanged()), this, SLOT(refreshEnergy()));
    connect(ddler, SIGNAL(onDeadlinechanged()), this, SLOT(refreshDdl()));
    connect(ddler, SIGNAL(onTimeExhausted()), this, SLOT(on_MsgWarning_Time()));
    connect(ddler, SIGNAL(onEnergyExhausted()), this, SLOT(on_MsgWarning_Energy()));
    connect(ddler, SIGNAL(onDeadlineExhausted()), this, SLOT(on_MsgInfo_Deadline()));
}
void deadline::on_todoList_itemDoubleClicked(QListWidgetItem *item)//双击todolist中项目实现项目转移至donelist
{
    //执行计数对话窗
    countItem *dlgCount = new countItem(this);

    QString todotext = item->text();
    QString donetext = item->text();


    //向doneList中添加项目
    if(dlgCount->exec()==QDialog::Accepted){
        double count = dlgCount->getItemCount();
        //qDebug()<<"count"<<count;
        QString sTime = QString::number(ddler->getItemTime(count, todotext));
        //qDebug()<<"time"<<sTime;
        //qDebug()<<"todotext: "<<todotext;


        if((ddler->getItemEnergy(count, todotext)+ddler->getEnergy()>=0)&&(ddler->getTime()>0-ddler->getItemTime(count, todotext))&&count!=0){//只有在三者条件都满足的情况下才可以添加新事件
            QListWidgetItem *i = new QListWidgetItem(donetext+"..................."+ sTime +"h");
            ui->doneList->insertItem(ui->doneList->currentRow(),i);
            ddler->changeDeadline(ddler->getItemDdl(count, todotext));
            ddler->changeEnergy(ddler->getItemEnergy(count, todotext));
            ddler->changeTime(ddler->getItemTime(count, todotext));
        }
        else if(ddler->getItemEnergy(count, todotext)+ddler->getEnergy()<0)
            emit ddler->onEnergyExhausted();
        else if(ddler->getItemTime(count,todotext)-ddler->getTime()<0)
            emit ddler->onTimeExhausted();
}
}
void deadline::on_doneList_itemDoubleClicked(QListWidgetItem *item)//双击itemlist终项目移除当前项，并改变时间。出大问题，我不会调回去呜呜呜呜呜！
{
    //处理item的数据
    QString str = item->text();
    QStringList list = str.split("...................");
    QCharRef doneTime_s = list[1][0];
    QString itemText = list[1];
    QString itemTime_s;
    for(int i=0;i<itemText.length();i++){
        if(itemText[i]>='0'&&itemText[i]<='9')
            itemTime_s.append(itemText[i]);
    }
    double itemTime = itemTime_s.toDouble();
    double doneTime = doneTime_s.digitValue();
    int count = doneTime/itemTime;

    ui->doneList->takeItem(ui->doneList->currentRow());

    //恢复lcdNumber的值
    ddler->recoverDeadline(ddler->getItemDdl(count, itemText));
    ddler->recoverEnergy(ddler->getItemEnergy(count, itemText));
    ddler->recoverTime(ddler->getItemTime(count, itemText));

}



void deadline::refreshTime(){
    lcdTime->display(ddler->getTime());
    qDebug()<<ddler->getTime();
}

void deadline::refreshEnergy(){
    lcdEnergy->display(ddler->getEnergy());
}

void deadline::refreshDdl(){
    lcdDdl->display(ddler->getDeadline());
}

void deadline::on_MsgWarning_Time(){
    QString dlgTitle="停一停！";
    QString strInfo = "别肝啦别肝啦没时间啦!";
    QMessageBox::warning(this, dlgTitle, strInfo);
}
void deadline::on_MsgWarning_Energy(){
    QString dlgTitle="你不对劲！";
    QString strInfo = "孩...子...没...力...量...了....";
    QMessageBox::warning(this, dlgTitle, strInfo);
}
void deadline::on_MsgInfo_Deadline(){
    QString dlgTitle = "针不戳！";
    QString strInfo = "ddl清干净啦！你可以快乐畅游于知识的海洋中了！";
    QMessageBox::information(this, dlgTitle, strInfo);
}

