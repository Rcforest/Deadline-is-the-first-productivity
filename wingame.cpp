#include "wingame.h"
#include "ui_wingame.h"

winGame::winGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::winGame)
{
    ui->setupUi(this);
    this->setWindowTitle("太棒啦！");
}

winGame::~winGame()
{
    delete ui;
}
