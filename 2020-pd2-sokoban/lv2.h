#ifndef LV2_H
#define LV2_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QMediaPlayer>
#include "player.h"

namespace Ui
{
    class LV2;
}

class LV2 : public QDialog
{
    Q_OBJECT

public:
    explicit LV2(QWidget *parent = nullptr);
    ~LV2();
    void keyPressEvent(QKeyEvent *e);
    void judge_win();

    QLabel *man;
    QLabel *box[3] = {nullptr};
    QLabel *map[9][9];
    QPushButton *next;
    int now[9][9];
    int boxp[3][2];
    int win = 0;
    int step = 0;
    bool ifwin = false;
    QMediaPlayer *player;
    int charindex = 1;
    bool isstart = true;
    QTimer *timer;
    QTime *time;

private slots:
    void on_restart_clicked();
    void changetime();

private:
    Ui::LV2 *ui;
    QCursor cursor;

    int position_x;
    int position_y;

    //0 ground . 1 wall  . 5 6 7 box . 3 storage . 4  man
    int map1[9][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 0},
                      {1, 1, 1, 1, 0, 4, 1, 1, 0},
                      {1, 1, 0, 0, 5, 0, 1, 1, 0},
                      {1, 1, 0, 1, 0, 1, 1, 1, 0},
                      {1, 0, 0, 1, 0, 1, 3, 1, 0},
                      {1, 0, 1, 0, 0, 6, 3, 1, 0},
                      {1, 0, 7, 0, 0, 0, 3, 1, 0},
                      {1, 1, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
};

#endif // LV2_H
