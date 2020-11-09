#include "countitem.h"
#include "ui_countitem.h"
#include <QMessageBox>

countItem::countItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::countItem)
{
    ui->setupUi(this);
    this->setWindowTitle("把次数安排上！");
}

countItem::~countItem()
{
   // QMessageBox::information(this,"Hint","Dialog deleting...");
    delete ui;
}

int countItem::getItemCount(){
    return ui->spinBox->value();
}

void countItem::setItemCount(int itemCount){
    ui->spinBox->setValue(itemCount);
}
