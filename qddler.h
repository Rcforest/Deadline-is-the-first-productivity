#ifndef QDDLER_H
#define QDDLER_H

#include <QObject>
#include <QtWidgets/QListWidgetItem>
#include <QtDebug>
#include <QMessageBox>




class Qddler : public QObject

{
    Q_OBJECT;


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
    bool changeTime(double time);
    bool changeEnergy(double time);
    bool changeDeadline(int deadline);




private:
    //widget里显示的参数
    int Week;
    int Energy;
    double Time;
    int Deadline;
    //事件对应的参数
    double time;
    int ddl;
    int energy;



signals:
    void onTimechanged();
    void onEnergychanged();
    void onDeadlinechanged();

    void onTimeExhausted();
    void onEnergyExhausted();
    void onDeadlineExhausted();




};

#endif // QDDLER_H
