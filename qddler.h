#ifndef QDDLER_H
#define QDDLER_H

#include <QObject>
#include <QtWidgets/QListWidgetItem>
#include <QtDebug>
#include <QMessageBox>




class Qddler : public QObject

{
    Q_OBJECT;
    //friend class deadline;


public:
    Qddler();
    ~Qddler();
    int getWeek();
    int getEnergy();
    double getTime();
    int getDeadline();
    double getItemTime(int count,QString todotext);
    int getItemDdl(int count, QString todotext);
    int getItemEnergy(int count, QString todotext);

    void changeTime(double time);
    void changeEnergy(double energy);
    void changeDeadline(int deadline);
    void changeWeek();

    void recoverTime(double time);
    void recoverEnergy(double energy);
    void recoverDeadline(int deadline);




private:
    //widget里显示的参数
    int Week;
    int Energy;
    double Time;
    int Deadline;
    //事件对应的参数
    double time;
    int ddl;
    double energy;



signals:
    void onTimechanged();
    void onEnergychanged();
    void onDeadlinechanged();
    void onWeekchanged();

    void onTimeExhausted();
    void onEnergyExhausted();
    void onDeadlineExhausted();

    void on_failGame();
    void on_winGame();




};

#endif // QDDLER_H
