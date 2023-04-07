#include "player.h"
#include <QDebug>

player::player()
{
    //qsrand(time(NULL));
}

void player::get_is_play(bool ifplay){
    is_play = ifplay;
}

void player :: jump(QGraphicsPixmapItem* monster, QGraphicsPixmapItem* clone, QGraphicsPixmapItem* super, QGraphicsPixmapItem* blackmage,QGraphicsPixmapItem*maple, int * score)
{
    if(is_play){
            t++;
            setPos(x(),y()-v);
            v+=g;
            if (this->collidesWithItem(monster)){
                    if(shield){
                        shield = false;
                        monster -> setY(-700);
                    }
                    else {
                        emit stop_game();
                    }

            }
            if (this->collidesWithItem(clone)){
                clone->setY(-2000);
                isclone = true;
                Timerclone = startTimer(5000);
            }
            if (this->collidesWithItem(super)){
                super->setY(-1500);
                shield = true;
            }
            if (this->collidesWithItem(blackmage)){
                    if (shield){
                        shield = false;
                        blackmage -> setY(-3000);
                    }
                    else{
                        emit stop_game();
                    }
                }

            if (this->collidesWithItem(maple)){
                *(score) *=1+0.1*(qrand()%10+1);
                maple->setPos(qrand()%450,-500);
            }
            }
            if (static_cast<QGraphicsPixmapItem*>(this)->y()>700) {
                emit stop_game();
            }
        }





double player::get_v(){
    return v;
}

void player::jump_again(){
    v = -(vi + g*t);
    if (580<y()+70)
        v=9.0;
    vi=v;
    t=0;
}

void player::timerEvent(QTimerEvent *e){
    if (e->timerId() == Timerclone){
        isclone = false;
    }
};
