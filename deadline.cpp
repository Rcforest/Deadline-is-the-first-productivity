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
    connect(ddler, SIGNAL(onWeekchanged()), this, SLOT(refreshWeek()));
    connect(ddler, SIGNAL(onTimeExhausted()), this, SLOT(on_MsgWarning_Time()));
    connect(ddler, SIGNAL(onEnergyExhausted()), this, SLOT(on_MsgWarning_Energy()));
    connect(ddler, SIGNAL(onDeadlineExhausted()), this, SLOT(on_MsgInfo_Deadline()));
    connect(ddler, SIGNAL(on_winGame()), this, SLOT(winGame()));
    connect(ddler, SIGNAL(on_failGame()),this, SLOT(failGame()));
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
        QString sTime = QString::number(ddler->getItemTime(count, todotext));


        if((ddler->getItemEnergy(count, todotext)+ddler->getEnergy()>=0)&&(ddler->getTime()-ddler->getItemTime(count, todotext)>0)&&count!=0){
            //只有在三者条件都满足的情况下才可以添加新事件
            QListWidgetItem *i = new QListWidgetItem(donetext+"..................."+ sTime +"h");
            ui->doneList->insertItem(ui->doneList->currentRow(),i);
            ddler->changeDeadline(ddler->getItemDdl(count, todotext));
            ddler->changeEnergy(ddler->getItemEnergy(count, todotext));
            ddler->changeTime(ddler->getItemTime(count, todotext));
        }
        else if(ddler->getItemEnergy(count, todotext)+ddler->getEnergy()<0)
            emit ddler->onEnergyExhausted();
        else if(ddler->getTime()-ddler->getItemTime(count, todotext)<0)
            emit ddler->onTimeExhausted();
}
}
void deadline::on_doneList_itemDoubleClicked(QListWidgetItem *item){//双击itemlist终项目移除当前项，并改变lcdNumber数值。
    //处理item的数据
    QString str = item->text();
    QStringList list = str.split("...................");
    QString doneText = list[1]; //获取后半段字符串
    QString itemText = list[0]; //获取前半段字符串
    QString itemTime_s;
    for(int i=0;i<itemText.length();i++){
        if(itemText[i]>='0'&&itemText[i]<='9')
            itemTime_s.append(itemText[i]);
    }
    QString doneTime_s;
    for(int i=0;i<doneText.length();i++){
        if(doneText[i]>='0'&&doneText[i]<='9')
            doneTime_s.append(doneText[i]);
    }
    double itemTime = itemTime_s.toDouble(); //获取事项单次时间；
    double doneTime = doneTime_s.toDouble();//获取事项总时间；
    int count = doneTime/itemTime;

    ui->doneList->takeItem(ui->doneList->currentRow());

    //恢复lcdNumber的值
    ddler->recoverDeadline(ddler->getItemDdl(count, itemText));
    ddler->recoverEnergy(ddler->getItemEnergy(count, itemText));
    ddler->recoverTime(ddler->getItemTime(count, itemText));

}



void deadline::refreshTime(){
    lcdTime->display(ddler->getTime());
}

void deadline::refreshEnergy(){
    lcdEnergy->display(ddler->getEnergy());
}

void deadline::refreshDdl(){
    lcdDdl->display(ddler->getDeadline());
}

void deadline::refreshWeek(){
    prbWeek ->setValue(ddler->getWeek());
    labWeek -> setText("第" + QString::number(ddler->getWeek()) + "周");
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


void deadline::on_btnNext_clicked()
{
    int cnt = ui->doneList->count();
    for(int i=0;i<cnt;i++){
        QListWidgetItem *item = ui->doneList->item(i);
        //处理item的数据
        QString str = item->text();
        QStringList list = str.split("...................");
        QString doneText = list[1]; //获取后半段字符串
        QString itemText = list[0]; //获取前半段字符串
        QString itemTime_s;
        for(int i=0;i<itemText.length();i++){//提取itemText中的时间
            if(itemText[i]>='0'&&itemText[i]<='9')
                itemTime_s.append(itemText[i]);
        }

        QString doneTime_s;
        for(int i=0;i<doneText.length();i++){//提取doneText中的时间
            if(doneText[i]>='0'&&doneText[i]<='9')
                doneTime_s.append(doneText[i]);
        }
        double itemTime = itemTime_s.toDouble(); //获取事项单次时间；
        double doneTime = doneTime_s.toDouble();//获取事项总时间；
        int count = doneTime/itemTime;

        //恢复lcdNumber的值,但保留待办数
        ddler->recoverEnergy(ddler->getItemEnergy(count, itemText));
        ddler->recoverTime(ddler->getItemTime(count, itemText));

    }
    ui->doneList->clear();

    ddler->changeWeek();
}

void deadline::winGame(){//赢得游戏对话窗
    class winGame *dlgWin = new class winGame(this);
    dlgWin->exec();
 }
void deadline::failGame(){//游戏失败对话窗
    class failGame *dlgFail = new class failGame(this);
    dlgFail->exec();
}

