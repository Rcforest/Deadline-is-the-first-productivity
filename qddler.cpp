#include "qddler.h"
#include "deadline.h"


Qddler::Qddler()
{
    Week = 1;
    Time = 24 * 7;
    time = 0;
    Energy = 100;
    Deadline = 0;
    ddl = 0;



}

Qddler::~Qddler(){

}

int Qddler::getWeek(){
    return Week;
}
double Qddler::getTime(){
    return Time;
}
int Qddler::getEnergy(){
    return Energy;
}
int Qddler::getDeadline(){
    return Deadline;
}
double Qddler::getItemTime(int count, QString todotext){//获取项目时间
    if(todotext=="摸鱼(2h)")  time = count * 2;
    else if(todotext=="翘课(2h)") time = count * 2;
    else if(todotext=="焊板子(5h)") time = count * 5;
    else if(todotext=="运动校园(0.25h)") time = count * 0.25;
    else if(todotext=="上课(5h)") time = count * 5;
    else if(todotext=="c++项目怎么才开始！(5h)") time = count * 5;
    else if(todotext=="睡觉(3h)") time = count * 3;
    else if(todotext=="小憩(0.5h)") time = count * 0.5;
    return time;
}
int Qddler::getItemDdl(int count, QString todotext){//获取项目ddl数
    if(todotext=="摸鱼(2h)")  ddl = count * 3;
    else if(todotext=="翘课(2h)") ddl = count * 4;
    else if(todotext=="上课(5h)") ddl = count * 2;
    else if(todotext=="焊板子(5h)") ddl = - count * 5;
    else if(todotext=="运动校园(0.25h)") ddl = - count * 1;
    else if(todotext=="c++项目怎么才开始！(5h)") ddl = -count * 2;
    else ddl = 0;
    return ddl;
}
int Qddler::getItemEnergy(int count, QString todotext){//获取项目消耗精力
    if(todotext=="摸鱼(2h)")  energy = count * 0.5;
    else if(todotext=="翘课(2h)") energy = count * 2;
    else if(todotext=="焊板子(5h)") energy = -count * 10;
    else if(todotext=="运动校园(0.25h)") energy = -count * 3;
    else if(todotext=="上课(5h)") energy = -count * 5;
    else if(todotext=="c++项目怎么才开始！(5h)")  energy = -count * 5;
    else if(todotext=="睡觉(3h)") energy = count * 3;
    else if(todotext=="小憩(0.5h)") energy = count * 0.5;
    return energy;
}

void Qddler::changeTime(double time){//改变时间，发送信号
       Time -= time;
       emit onTimechanged();
}
void Qddler::changeEnergy(double energy){//改变精力值，发送信号
        if(Energy+energy>100) energy=0;
        Energy += energy;
    emit onEnergychanged();
}
void Qddler::changeDeadline(int deadline){//改变ddl值，发送信号
    if(Deadline+deadline<=0){ //改变ddl额度
        deadline = -Deadline;
        if(Deadline!=0)
        emit onDeadlineExhausted();
    }

    Deadline+=deadline;
    emit onDeadlinechanged();

 }
void Qddler::changeWeek(){
    if(Week!=10) {
        Week +=1;
        emit onWeekchanged();
    }
    else{
        if(Deadline==0) emit on_winGame();
        else emit on_failGame();
    }
}



void Qddler::recoverTime(double time){//恢复时间
    Time += time;
    emit onTimechanged();
}
void Qddler::recoverEnergy(double energy){//恢复精力
    if(Energy+energy>100) energy=0;
    Energy -= energy;
    emit onEnergychanged();
}
void Qddler::recoverDeadline(int deadline){//恢复ddl
    Deadline -= deadline;
    emit onDeadlinechanged();
}
