#ifndef COUNTITEM_H
#define COUNTITEM_H

#include <QDialog>

namespace Ui {
class countItem;
}

class countItem : public QDialog
{
    Q_OBJECT

public:
    explicit countItem(QWidget *parent = nullptr);
    ~countItem();
    int getItemCount();
    void setItemCount(int itemCount);

private:
    Ui::countItem *ui;

//private slots:
//    void on_btnCancel_clicked();
};

#endif // COUNTITEM_H
