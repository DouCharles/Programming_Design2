#include "plat.h"
#include <QDebug>
plat::plat()
{
    //qsrand(time(nullptr));


}

void plat::generate(double pos_x=0.0,double pos_y=0.0){
    x=pos_x;
    while (x>410)
        x=qrand()%500;
    y=pos_y;
    setPos(x,y);
}

bool plat::collide_judge(player* role){
    bool iscollide = role->collidesWithItem(this,Qt::IntersectsItemBoundingRect);
    if (iscollide){
        if ((static_cast<QGraphicsPixmapItem*>(role)->y()< static_cast<QGraphicsPixmapItem*>(this)->y()-55.0)&& (static_cast<QGraphicsPixmapItem*>(role)->y() >static_cast<QGraphicsPixmapItem*>(this)->y() -85.0)){
            return true;
        }
    }
    return false;
}

double plat::get_y(){
    return  y;
}

void plat::godown(QWidget *here,double distance){
    if(c*2<distance){
        setY(static_cast<QGraphicsPixmapItem*>(this)->y()+2);
        c++;
        if (static_cast<QGraphicsPixmapItem*>(this)->y()>=700)
            setPos(qrand()%410,0);
    }
    else if (c*2>=static_cast<int>(distance)){
        c=0;
        disconnect(here,SIGNAL(itemgodown_signal(QWidget*,double)),this,SLOT(godown(QWidget *,double)));

    }
}

void plat::move(bool){}


