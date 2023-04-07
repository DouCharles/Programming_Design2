#ifndef PLAT2_H
#define PLAT2_H

#include "plat.h"

class plat2 : public plat
{
public:
    plat2();
    bool collide_plat(plat *);

public slots:
    void move(bool);

private:
    double orginal_x;
    double orginal_y;
    QTimer *timer;
    double v = 3;
};

#endif // PLAT2_H
