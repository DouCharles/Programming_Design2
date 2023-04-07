#ifndef LV1_H
#define LV1_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include "lv2.h"
#include "player.h"
namespace Ui
{
    class LV1;
}

class LV1 : public QDialog
{
    Q_OBJECT

public:
    explicit LV1(QWidget *parent = nullptr);
    ~LV1();
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
    void on_next_clicked();
    void on_skill_clicked();
    void changetime();

private:
    Ui::LV1 *ui;
    LV2 *lv_2 = new LV2;
    QCursor cursor;
    int position_x;
    int position_y;

    //0 ground . 1 wall  . 5 6 7 box . 3 storage . 4  man
    int map1[9][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 0, 0, 4, 1},
                      {1, 1, 1, 1, 1, 5, 6, 0, 1},
                      {1, 3, 1, 1, 1, 0, 7, 0, 1},
                      {1, 3, 1, 1, 1, 0, 0, 0, 1},
                      {1, 3, 0, 0, 0, 0, 0, 0, 1},
                      {1, 0, 0, 1, 0, 0, 0, 0, 1},
                      {1, 1, 1, 1, 0, 0, 0, 0, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1, 1}};
};

#endif // LV1_H
