#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QTime>
#include <QTimer>



class player : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    void get_is_play(bool);
    double get_v();
    bool shield = false;
    bool isclone = false;

signals:
    void stop_game();

public slots:
    void jump(QGraphicsPixmapItem*,QGraphicsPixmapItem*, QGraphicsPixmapItem*, QGraphicsPixmapItem*,QGraphicsPixmapItem*,int *);
    void jump_again();
    void timerEvent(QTimerEvent *e);

private:

    bool is_play;
    bool isCollide;
    double g = -0.2;
    double v = 9.0;
    double vi = 9.0;
    int t=0;
    int Timerclone;
    int Timersuper;
};

#endif // PLAYER_H
