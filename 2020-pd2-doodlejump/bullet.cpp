#include "bullet.h"

bullet::bullet()
{
    qsrand(time(NULL));
}

void bullet::up(QGraphicsPixmapItem* monster,QGraphicsScene *scene){
    if (is_play){
        setPos(x(),y()-15);
        if(y()<0){
            this->scene()->removeItem(this);
            delete this;
        }
        else if(monster!=nullptr){
            if (static_cast<QGraphicsPixmapItem*>(this)->collidesWithItem(monster)){
                monster->setPos(qrand()%450,-(qrand()%300+200));
                this->scene()->removeItem(this);
                delete  this;
            }
        }
    }
}

void bullet::left(QGraphicsPixmapItem* monster,QGraphicsScene *scene){
    if (is_play){
        setPos(x()-15,y()-15);
        if(y()<0){
            this->scene()->removeItem(this);
            delete this;
        }
        else if(monster!=nullptr){
            if (static_cast<QGraphicsPixmapItem*>(this)->collidesWithItem(monster)){
                monster->setPos(qrand()%450,-(qrand()%300+200));
                this->scene()->removeItem(this);
                delete  this;
            }
        }
    }
}

void bullet::right(QGraphicsPixmapItem* monster,QGraphicsScene *scene){
    if (is_play){
        setPos(x()+15,y()-15);
        if(y()<0){
            this->scene()->removeItem(this);
            delete this;
        }
        else if(monster!=nullptr){
            if (static_cast<QGraphicsPixmapItem*>(this)->collidesWithItem(monster)){
                monster->setPos(qrand()%450,-(qrand()%300+200));
                this->scene()->removeItem(this);
                delete  this;
            }
        }
    }
}

void bullet::get_is_play(bool ifplay){
    is_play = ifplay;
}
