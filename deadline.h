#ifndef DEADLINE_H
#define DEADLINE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QtWidgets>
#include <QString>

#include "qddler.h"
#include "countitem.h"
#include "wingame.h"
#include "failgame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class deadline; }
QT_END_NAMESPACE

class deadline : public QMainWindow
{
    Q_OBJECT

public:
    deadline(QWidget *parent = nullptr);
    ~deadline();


private:
    Ui::deadline *ui;
    Qddler *ddler;
    QLabel *labWeek;
    QProgressBar *prbWeek;
    QLCDNumber *lcdTime, *lcdEnergy, *lcdDdl;

    void iniconnect();
    void iniUI();




private slots:


    void on_todoList_itemDoubleClicked(QListWidgetItem *item);
    void refreshTime();
    void refreshEnergy();
    void refreshDdl();
    void refreshWeek();
    void on_MsgWarning_Time();
    void on_MsgWarning_Energy();
    void on_MsgInfo_Deadline();
    void on_doneList_itemDoubleClicked(QListWidgetItem *item);
    void on_btnNext_clicked();
    void winGame();
    void failGame();
};








#endif // deadline_H
