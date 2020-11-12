#include "failgame.h"
#include "ui_failgame.h"

failGame::failGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::failGame)
{
    ui->setupUi(this);
    this->setWindowTitle("很遗憾:(");
}

failGame::~failGame()
{
    delete ui;
}
