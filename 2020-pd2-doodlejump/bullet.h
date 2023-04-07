#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QWidget>
#include <random>
#include <ctime>

class bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    void get_is_play(bool );

public slots:
    void up(QGraphicsPixmapItem* ,QGraphicsScene*);
    void left(QGraphicsPixmapItem* ,QGraphicsScene*);
    void right(QGraphicsPixmapItem* ,QGraphicsScene*);
private:
    bool is_play;
};

#endif // BULLET_H
