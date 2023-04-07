#ifndef PLAT_H
#define PLAT_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "player.h"

class plat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    plat();
    virtual void generate(double, double);
    virtual bool collide_judge(player *);
    virtual double get_y();


public slots:
    virtual void move(bool);
    virtual void godown(QWidget*,double);


protected:
    int c =0;
    double x;
    double y;

};

#endif // PLAT_H
