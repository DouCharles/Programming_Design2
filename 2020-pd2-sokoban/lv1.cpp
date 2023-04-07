#include "lv1.h"
#include "ui_lv1.h"
#include <QDebug>

LV1::LV1(QWidget *parent) : QDialog(parent),
                            ui(new Ui::LV1)
{
    ui->setupUi(this);
    ui->next->hide();
    ui->step_number->setNum(step);
    ui->win->hide();
    //control the size of the window
    Qt::WindowFlags size = nullptr;
    size |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(size);
    setFixedSize(800, 600);

    // set up the background
    this->setAutoFillBackground(true);
    QPalette bg = this->palette();
    bg.setBrush(QPalette::Window,
                QBrush(QPixmap(":/image/lvbg").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(bg);

    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/image/lv1music"));
    player->setVolume(80);

    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));

    QPixmap manpic(":/image/person");
    QPixmap boxpic(":/image/box");
    QPixmap wallpic(":/image/wall");
    QPixmap goalpic(":/image/goal");
    QPixmap skillpic(":/image/skill");


    QPixmap cursorpic(":/image/hand");
    QSize cSize(25,25);
    QPixmap CScal = cursorpic.scaled(cSize, Qt::KeepAspectRatio);
    cursor = QCursor(CScal);
    this->setCursor(cursor);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map1[i][j] == 0)
                continue;
            else if (map1[i][j] == 1)
            {
                map[i][j] = new QLabel(this);
                map[i][j]->setGeometry(50 * j, 50 * i, 50, 50);
                map[i][j]->setPixmap((wallpic.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio)));
            }
            else if (map1[i][j] > 4)
            {
                map[i][j] = new QLabel(this);
                map[i][j]->setGeometry(50 * j, 50 * i, 50, 50);
                map[i][j]->setPixmap((boxpic.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio)));
            }
            else if (map1[i][j] == 4)
            {
                man = new QLabel(this);
                man->setGeometry(50 * j, 50 * i, 50, 50);
                man->setPixmap((manpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
                position_x = j;
                position_y = i;
            }
            else if (map1[i][j] == 3)
            {
                map[i][j] = new QLabel(this);
                map[i][j]->setGeometry(50 * j, 50 * i, 50, 50);
                map[i][j]->setPixmap((goalpic.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio)));
            }
        }
    }
    for (int k = 0; k < 9; k++)
    {
        for (int l = 0; l < 9; l++)
        {
            now[k][l] = map1[k][l];
        }
    }
    map[2][5]->raise();
    map[2][6]->raise();
    map[3][6]->raise();
    man->raise();

    ui->skill->setIcon(skillpic);
    ui->skill->setIconSize(ui->skill->size());
    ui->skill->hide();

    isstart = false;
    timer = new QTimer;
    time = new QTime(0, 0, 0);

    ui->timer->setDigitCount(8);
    ui->timer->setSegmentStyle(QLCDNumber::Flat);
    ui->timer->display(time->toString("mm:ss"));

    connect(timer,SIGNAL(timeout()),this,SLOT(changetime()));
}

LV1::~LV1()
{
    delete ui;
}



void LV1::keyPressEvent(QKeyEvent *e)
{
    QPixmap manpic(":/image/person");
    QPixmap man2pic(":/image/person2");
    QPixmap man3pic(":/image/person3");
    QPixmap man4pic(":/image/person4");
    QPixmap manLEFTpic(":/image/personleft");
    QPixmap man2LEFTpic(":/image/person2left");
    QPixmap man3RIGHTpic(":/image/person3right");
    QPixmap man4LEFTpic(":/image/person4left");
    switch (e->key())
    {
    case Qt::Key_W:
    {
        player::up(&position_x, &position_y, man, &now[0][0], map[2][5], map[2][6], map[3][6], &boxp[0][0], &step, ifwin);
        ui->step_number->setNum(step);
        judge_win();
        if (now[7][7]==4)
            ui->skill->show();
        break;
    }
    case Qt::Key_S:
    {
        player::down(&position_x, &position_y, man, &now[0][0], map[2][5], map[2][6], map[3][6], &boxp[0][0], &step, ifwin);
        ui->step_number->setNum(step);
        judge_win();
        if (now[7][7]==4)
            ui->skill->show();
        break;
    }
    case Qt::Key_D:
    {
        player::right(&position_x, &position_y, man, &now[0][0], map[2][5], map[2][6], map[3][6], &boxp[0][0], &step, ifwin);
        ui->step_number->setNum(step);
        judge_win();
        switch(charindex){
        case 1:{
            man->setPixmap((manpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 2:{
            man->setPixmap((man2pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 3:{
            man->setPixmap((man3RIGHTpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 4:{
            man->setPixmap((man4pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        }
        if (now[7][7]==4)
            ui->skill->show();
        break;
    }
    case Qt::Key_A:
    {
        player::left(&position_x, &position_y, man, &now[0][0], map[2][5], map[2][6], map[3][6], &boxp[0][0], &step, ifwin);
        ui->step_number->setNum(step);
        judge_win();
        switch(charindex){
        case 1:{
            man->setPixmap((manLEFTpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 2:{
            man->setPixmap((man2LEFTpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 3:{
            man->setPixmap((man3pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        case 4:{
            man->setPixmap((man4LEFTpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
            break;
        }
        }
        if (now[7][7]==4)
            ui->skill->show();
        break;
    }
    }
}

void LV1::judge_win()
{
    if (now[3][1] > 4){
        win++;
    }
    if (now[4][1] > 4){
        win++;
    }
    if (now[5][1] > 4){
        win++;
    }
    if (win == 3)
    {
        timer->stop();
        ui->next->show();
        ui->win->show();
        ifwin = true;
    }
    win = 0;
}

void LV1::on_restart_clicked()
{
    step = 0;
    ui->step_number->setNum(step);
    int c = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map1[i][j] > 4)
            {

                map[i][j]->move(50 * j, 50 * i);
            }
            else if (map1[i][j] == 4)
            {
                man->move(50 * j, 50 * i);
                position_x = j;
                position_y = i;
            }
            c++;
        }
    }
    for (int k = 0; k < 9; k++)
    {
        for (int l = 0; l < 9; l++)
        {
            now[k][l] = map1[k][l];
        }
    }
    ui->skill->hide();
    ui->win->hide();
    ui->next->hide();
    time->setHMS(0, 0, 0);
    ui->timer->display(time->toString("mm:ss"));
    if (!isstart)
        timer->start(1000);
}

void LV1::on_next_clicked()
{
    QPixmap manpic(":/image/person");
    QPixmap man2pic(":/image/person2");
    QPixmap man3pic(":/image/person3");
    QPixmap man4pic(":/image/person4");
    player->stop();
    this->hide();
    switch(charindex){
    case 1:{
        lv_2->man->setPixmap((manpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 2:{
        lv_2->man->setPixmap((man2pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 3:{
        lv_2->man->setPixmap((man3pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 4:{
        lv_2->man->setPixmap((man4pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    }
    lv_2->charindex=charindex;
    lv_2->player->play();
    lv_2->show();
    lv_2->timer->start(1000);
}

void LV1::on_skill_clicked()
{
    QPixmap manpic(":/image/person");
    QPixmap man2pic(":/image/person2");
    QPixmap man3pic(":/image/person3");
    QPixmap man4pic(":/image/person4");
    player->stop();
    this->hide();
    switch(charindex){
    case 1:{
        lv_2->man->setPixmap((manpic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 2:{
        lv_2->man->setPixmap((man2pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 3:{
        lv_2->man->setPixmap((man3pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    case 4:{
        lv_2->man->setPixmap((man4pic.scaled(man->width(), man->height(), Qt::KeepAspectRatio)));
        break;
    }
    }
    lv_2->charindex=charindex;
    timer->stop();
    lv_2->player->play();
    lv_2->show();
    lv_2->timer->start(1000);
}

void LV1::changetime()
{
    *time = time->addSecs(1);
    ui->timer->display(time->toString("mm:ss"));
}

