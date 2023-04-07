#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <time.h>
#include <random>
#include <QTimerEvent>
#include <QTime>
#include <QGraphicsItemGroup>
#include "bullet.h"
#include "player.h"
#include "plat1.h"
#include "plat2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    ~MainWindow();
    player *role = new player;

signals:
    void rolejump(QGraphicsPixmapItem*, QGraphicsPixmapItem* ,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,int *);
    void bfly(QGraphicsPixmapItem* ,QGraphicsScene*);
    void judge();
    void jump_again();
    void itemgodown_signal(QWidget*,double);
    void godown_signal(QGraphicsPixmapItem *,double,int);
    void godown_signal1(QGraphicsPixmapItem *,double,int);
    void godown_signal2(QGraphicsPixmapItem *,double,int);
    void godown_signal3(QGraphicsPixmapItem *,double,int);
    void godown_signal4(QGraphicsPixmapItem *,double,int);
    void platgodown(double);
    void platMove(bool);

private slots:
    void on_start_clicked();
    void on_stop_clicked();
    void timerEvent(QTimerEvent *e);
    void judge_collide();
    void set_role_v();
    void gameover();
    void godown(QGraphicsPixmapItem *,double,int);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int Timer1;
    int TimerGodown;
    int TimerJumpAgain;
    //int TimerGodown2;
    bool haveplat =false;
    bool is_play = false;
    plat1 platA[10];
    plat2 platB[2];
    plat1 platstart;
    plat *platptr;
    plat *platptrformer;
    double role_v;
    bool isCollide = false;
    bool isCollide_start;
    bool newagain = false;
    int newc[10];
    int newc2[10];
    int round=0;
    QGraphicsPixmapItem *monster;
    QGraphicsPixmapItem *clone;
    QGraphicsPixmapItem *super;
    QGraphicsPixmapItem *blackmage;
    QGraphicsPixmapItem *maple;
    int score=0;
    double distance;
    int c[5]={0};
};

#endif // MAINWINDOW_H
