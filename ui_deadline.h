/********************************************************************************
** Form generated from reading UI file 'deadline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEADLINE_H
#define UI_DEADLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deadline
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListWidget *doneList;
    QListWidget *todoList;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnBuild;
    QPushButton *btnDorm;
    QPushButton *btnLab;
    QPushButton *btnLibary;
    QPushButton *btnNext;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Vlaylab;
    QLabel *labTime;
    QLabel *labEnergy;
    QLabel *labDdl;
    QVBoxLayout *Vlaylcd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deadline)
    {
        if (deadline->objectName().isEmpty())
            deadline->setObjectName(QString::fromUtf8("deadline"));
        deadline->resize(962, 656);
        centralwidget = new QWidget(deadline);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 601, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doneList = new QListWidget(gridLayoutWidget);
        doneList->setObjectName(QString::fromUtf8("doneList"));

        gridLayout->addWidget(doneList, 1, 2, 1, 1);

        todoList = new QListWidget(gridLayoutWidget);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        new QListWidgetItem(todoList);
        todoList->setObjectName(QString::fromUtf8("todoList"));

        gridLayout->addWidget(todoList, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(410, 420, 201, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnBuild = new QPushButton(gridLayoutWidget_2);
        btnBuild->setObjectName(QString::fromUtf8("btnBuild"));

        gridLayout_2->addWidget(btnBuild, 0, 0, 1, 1);

        btnDorm = new QPushButton(gridLayoutWidget_2);
        btnDorm->setObjectName(QString::fromUtf8("btnDorm"));

        gridLayout_2->addWidget(btnDorm, 2, 0, 1, 1);

        btnLab = new QPushButton(gridLayoutWidget_2);
        btnLab->setObjectName(QString::fromUtf8("btnLab"));

        gridLayout_2->addWidget(btnLab, 2, 1, 1, 1);

        btnLibary = new QPushButton(gridLayoutWidget_2);
        btnLibary->setObjectName(QString::fromUtf8("btnLibary"));

        gridLayout_2->addWidget(btnLibary, 0, 1, 1, 1);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(410, 510, 121, 41));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 420, 241, 141));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Vlaylab = new QVBoxLayout();
        Vlaylab->setObjectName(QString::fromUtf8("Vlaylab"));
        labTime = new QLabel(horizontalLayoutWidget);
        labTime->setObjectName(QString::fromUtf8("labTime"));

        Vlaylab->addWidget(labTime);

        labEnergy = new QLabel(horizontalLayoutWidget);
        labEnergy->setObjectName(QString::fromUtf8("labEnergy"));

        Vlaylab->addWidget(labEnergy);

        labDdl = new QLabel(horizontalLayoutWidget);
        labDdl->setObjectName(QString::fromUtf8("labDdl"));

        Vlaylab->addWidget(labDdl);


        horizontalLayout->addLayout(Vlaylab);

        Vlaylcd = new QVBoxLayout();
        Vlaylcd->setObjectName(QString::fromUtf8("Vlaylcd"));

        horizontalLayout->addLayout(Vlaylcd);

        deadline->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(deadline);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        deadline->setStatusBar(statusbar);

        retranslateUi(deadline);

        QMetaObject::connectSlotsByName(deadline);
    } // setupUi

    void retranslateUi(QMainWindow *deadline)
    {
        deadline->setWindowTitle(QCoreApplication::translate("deadline", "deadline\346\230\257\347\254\254\344\270\200\347\224\237\344\272\247\345\212\233\357\274\201", nullptr));

        const bool __sortingEnabled = todoList->isSortingEnabled();
        todoList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = todoList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("deadline", "\347\277\230\350\257\276(2h)", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = todoList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("deadline", "\347\235\241\350\247\211(3h)", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = todoList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("deadline", "\345\260\217\346\206\251(0.5h)", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = todoList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("deadline", "\344\270\212\350\257\276(5h)", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = todoList->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("deadline", "\346\221\270\351\261\274(2h)", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = todoList->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("deadline", "\347\204\212\346\235\277\345\255\220(5h)", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = todoList->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("deadline", "\350\277\220\345\212\250\346\240\241\345\233\255(0.25h)", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = todoList->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("deadline", "c++\351\241\271\347\233\256\346\200\216\344\271\210\346\211\215\345\274\200\345\247\213\357\274\201(5h)", nullptr));
        todoList->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("deadline", "\350\277\231\345\221\250\346\200\216\344\271\210\345\256\211\346\216\222\357\274\237", nullptr));
        btnBuild->setText(QCoreApplication::translate("deadline", "\346\225\231\345\255\246\346\245\274", nullptr));
        btnDorm->setText(QCoreApplication::translate("deadline", "\345\256\277\350\210\215", nullptr));
        btnLab->setText(QCoreApplication::translate("deadline", "\345\256\236\351\252\214\345\256\244", nullptr));
        btnLibary->setText(QCoreApplication::translate("deadline", "\345\233\276\344\271\246\351\246\206", nullptr));
        btnNext->setText(QCoreApplication::translate("deadline", "\344\270\213\344\270\200\345\221\250", nullptr));
        labTime->setText(QCoreApplication::translate("deadline", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\346\227\266\351\227\264</span></p></body></html>", nullptr));
        labEnergy->setText(QCoreApplication::translate("deadline", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\347\262\276\345\212\233</span></p></body></html>", nullptr));
        labDdl->setText(QCoreApplication::translate("deadline", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\345\276\205\345\212\236\346\225\260</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deadline: public Ui_deadline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEADLINE_H
