/********************************************************************************
** Form generated from reading UI file 'countitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTITEM_H
#define UI_COUNTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_countItem
{
public:
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpinBox *spinBox;

    void setupUi(QDialog *countItem)
    {
        if (countItem->objectName().isEmpty())
            countItem->setObjectName(QString::fromUtf8("countItem"));
        countItem->resize(440, 182);
        countItem->setSizeGripEnabled(false);
        btnOK = new QPushButton(countItem);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(220, 140, 93, 28));
        btnCancel = new QPushButton(countItem);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(330, 140, 93, 28));
        spinBox = new QSpinBox(countItem);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 70, 131, 41));

        retranslateUi(countItem);
        QObject::connect(btnOK, SIGNAL(clicked()), countItem, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), countItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(countItem);
    } // setupUi

    void retranslateUi(QDialog *countItem)
    {
        countItem->setWindowTitle(QCoreApplication::translate("countItem", "Dialog", nullptr));
        btnOK->setText(QCoreApplication::translate("countItem", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("countItem", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class countItem: public Ui_countItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTITEM_H
