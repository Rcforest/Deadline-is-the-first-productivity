#ifndef WINGAME_H
#define WINGAME_H

#include <QDialog>

namespace Ui {
class winGame;
}

class winGame : public QDialog
{
    Q_OBJECT

public:
    explicit winGame(QWidget *parent = nullptr);
    ~winGame();

private:
    Ui::winGame *ui;
};

#endif // WINGAME_H
