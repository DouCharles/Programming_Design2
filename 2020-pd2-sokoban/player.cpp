#include "player.h"
#include "mainwindow.h"
player::player()
{
}

//*int first = the initial map
//0 ground . 1 wall  . 5 6 7 box . 3 storage . 4  man
void player::up(int *x, int *y, QLabel *man, int *first,
                QLabel *box1, QLabel *box2,
                QLabel *box3, int *boxp, int *step, bool ifwin)
{
    if (*(first + 9 * ((*y) - 1) + (*x)) == 1)
    {
        return;
    }
    else if ((*(first + 9 * ((*y) - 1) + (*x)) > 4))
    {
        if ((*(first + 9 * ((*y) - 2) + (*x)) == 1) || (*(first + 9 * ((*y) - 2) + (*x)) > 4))
        {
            return;
        }
        switch (*(first + 9 * ((*y) - 1) + (*x)))
        {
        case 5:
        {
            box1->move(box1->x(), box1->y() - 50);
            *(first + 9 * ((*y) - 2) + (*x)) = 5;
            *(first + 9 * ((*y) - 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 1) -= 1;
            break;
        }
        case 6:
        {
            box2->move(box2->x(), box2->y() - 50);
            *(first + 9 * ((*y) - 2) + (*x)) = 6;
            *(first + 9 * ((*y) - 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 3) -= 1;
            break;
        }
        case 7:
        {
            box3->move(box3->x(), box3->y() - 50);
            *(first + 9 * ((*y) - 2) + (*x)) = 7;
            *(first + 9 * ((*y) - 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 5) -= 1;
            break;
        }
        }
        man->move(man->x(), man->y() - 50);
        (*y)--;
        if(!ifwin){
            (*step)++;
        }
    }
    else
    {
        man->move(man->x(), man->y() - 50);
        *(first + 9 * ((*y) - 1) + (*x)) = 4;
        *(first + 9 * ((*y))+(*x))=0;
        (*y)--;
        if(!ifwin){
            (*step)++;
        }
    }
}
void player::down(int *x, int *y, QLabel *man, int *first,
                  QLabel *box1, QLabel *box2,
                  QLabel *box3, int *boxp, int *step, bool ifwin)
{
    if (*(first + 9 * ((*y) + 1) + (*x)) == 1)
    {
        return;
    }
    else if ((*(first + 9 * ((*y) + 1) + (*x)) > 4))
    {
        if ((*(first + 9 * ((*y) + 2) + (*x)) == 1) || (*(first + 9 * ((*y) + 2) + (*x)) > 4))
        {
            return;
        }
        switch (*(first + 9 * ((*y) + 1) + (*x)))
        {
        case 5:
        {
            box1->move(box1->x(), box1->y() + 50);
            *(first + 9 * ((*y) + 2) + (*x)) = 5;
            *(first + 9 * ((*y) + 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 1) += 1;
            break;
        }
        case 6:
        {
            box2->move(box2->x(), box2->y() + 50);
            *(first + 9 * ((*y) + 2) + (*x)) = 6;
            *(first + 9 * ((*y) + 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 3) += 1;
            break;
        }
        case 7:
        {
            box3->move(box3->x(), box3->y() + 50);
            *(first + 9 * ((*y) + 2) + (*x)) = 7;
            *(first + 9 * ((*y) + 1) + (*x)) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 5) += 1;
            break;
        }
        }
        man->move(man->x(), man->y() + 50);
        (*y)++;
        if(!ifwin){
            (*step)++;
        }
    }
    else
    {
        man->move(man->x(), man->y() + 50);
        *(first + 9 * ((*y) + 1) + (*x)) = 4;
        *(first + 9 * ((*y))+(*x))=0;
        (*y)++;
        if(!ifwin){
            (*step)++;
        }
    }
}

void player::right(int *x, int *y, QLabel *man, int *first,
                   QLabel *box1, QLabel *box2,
                   QLabel *box3, int *boxp, int *step, bool ifwin)
{
    if (*(first + 9 * (*y) + ((*x) + 1)) == 1)
    {
        return;
    }
    else if ((*(first + 9 * ((*y)) + (*x) + 1) > 4))
    {
        if ((*(first + 9 * ((*y)) + (*x) + 2) == 1) || (*(first + 9 * ((*y)) + (*x) + 2) > 4))
        {
            return;
        }
        switch (*(first + 9 * ((*y)) + (*x) + 1))
        {
        case 5:
        {
            box1->move(box1->x() + 50, box1->y());
            *(first + 9 * ((*y)) + (*x) + 2) = 5;
            *(first + 9 * ((*y)) + (*x) + 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp) += 1;
            break;
        }
        case 6:
        {
            box2->move(box2->x() + 50, box2->y());
            *(first + 9 * ((*y)) + (*x) + 2) = 6;
            *(first + 9 * ((*y)) + (*x) + 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 2) += 1;
            break;
        }
        case 7:
        {
            box3->move(box3->x() + 50, box3->y());
            *(first + 9 * ((*y)) + (*x) + 2) = 7;
            *(first + 9 * ((*y)) + (*x) + 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 4) += 1;
            break;
        }
        }
        man->move(man->x() + 50, man->y());
        (*x)++;
        if(!ifwin){
            (*step)++;
        }
    }
    else
    {
        man->move(man->x() + 50, man->y());
        *(first + 9 * ((*y)) + (*x) + 1) = 4;
        *(first + 9 * ((*y))+(*x))=0;
        (*x)++;
        if(!ifwin){
            (*step)++;
        }
    }
}
void player::left(int *x, int *y, QLabel *man, int *first,
                  QLabel *box1, QLabel *box2,
                  QLabel *box3, int *boxp, int *step, bool ifwin)
{
    if (*(first + 9 * (*y) + ((*x) - 1)) == 1)
    {
        return;
    }
    else if ((*(first + 9 * ((*y)) + (*x) - 1) > 4))
    {
        if ((*(first + 9 * ((*y)) + (*x) - 2) == 1) || (*(first + 9 * ((*y)) + (*x) - 2) > 4))
        {
            return;
        }
        switch (*(first + 9 * ((*y)) + (*x) - 1))
        {
        case 5:
        {
            box1->move(box1->x() - 50, box1->y());
            *(first + 9 * ((*y)) + (*x) - 2) = 5;
            *(first + 9 * ((*y)) + (*x) - 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp) -= 1;
            break;
        }
        case 6:
        {
            box2->move(box2->x() - 50, box2->y());
            *(first + 9 * ((*y)) + (*x) - 2) = 6;
            *(first + 9 * ((*y)) + (*x) - 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 2) -= 1;
            break;
        }
        case 7:
        {
            box3->move(box3->x() - 50, box3->y());
            *(first + 9 * ((*y)) + (*x) - 2) = 7;
            *(first + 9 * ((*y)) + (*x) - 1) = 4;
            *(first + 9 * ((*y))+(*x))=0;
            *(boxp + 4) -= 1;
            break;
        }
        }
        man->move(man->x() - 50, man->y());
        (*x)--;
        if(!ifwin){
            (*step)++;
        }
    }
    else
    {
        man->move(man->x() - 50, man->y());
        *(first + 9 * ((*y)) + (*x) - 1) = 4;
        *(first + 9 * ((*y))+(*x))=0;
        (*x)--;
        if(!ifwin){
            (*step)++;
        }
    }
}
