#ifndef FAILGAME_H
#define FAILGAME_H

#include <QDialog>

namespace Ui {
class failGame;
}

class failGame : public QDialog
{
    Q_OBJECT

public:
    explicit failGame(QWidget *parent = nullptr);
    ~failGame();

private:
    Ui::failGame *ui;
};

#endif // FAILGAME_H
