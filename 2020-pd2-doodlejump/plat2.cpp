#include "plat2.h"
#include <QDebug>

plat2::plat2()
{
}

bool plat2::collide_plat(plat * otherplat){
    double nowx=x;
    bool iscollide = false;
    for (int i=-130;i<131;i++){
        x = nowx;
        x = x + i;
        setX(x);
        iscollide = this->collidesWithItem(otherplat);
        if (iscollide){
            x=nowx;
            setX(nowx);
            return  iscollide;
        }
    }
    x=nowx;
    setX(nowx);
    return iscollide;
}

void plat2::move(bool is_play){
    orginal_x = x;
    orginal_y = y;
    if ((static_cast<QGraphicsPixmapItem*>(this)->x())>orginal_x+100 || ((static_cast<QGraphicsPixmapItem*>(this)->x()) > 450) ){
        v = -3;
    }
    else if ((static_cast<QGraphicsPixmapItem*>(this)->x())<orginal_x-100 || (static_cast<QGraphicsPixmapItem*>(this)->x()) < 0){
        v = 3;
    }
    if (is_play)
        setX(static_cast<QGraphicsPixmapItem*>(this)->x()+v);
}
