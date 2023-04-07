#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QLabel>

class player : public QObject
{
    Q_OBJECT

public:
    player();
    void static up(int *, int *, QLabel *, int *, QLabel *, QLabel *, QLabel *, int *, int *, bool);
    void static down(int *, int *, QLabel *, int *, QLabel *, QLabel *, QLabel *, int *, int *, bool);
    void static right(int *, int *, QLabel *, int *, QLabel *, QLabel *, QLabel *, int *, int *, bool);
    void static left(int *, int *, QLabel *, int *, QLabel *, QLabel *, QLabel *, int *, int *, bool);

    // void keyPressEvent(QKeyEvent *e);

signals:

public slots:

private:
    int position_x;
    int position_y;
};

#endif // PLAYER_H
