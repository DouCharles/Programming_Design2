#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 500, 700))
{
    qsrand(time(NULL));
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    role->setPixmap(QPixmap(":/pics/role").scaled(40,70));
    role->setPos(250,580);
    scene->addItem(static_cast<QGraphicsPixmapItem*>(role));

    //the super ,clone icon and the stop button hide
    ui->stop->hide();
    ui->super_2->setPixmap(QPixmap(":/pics/super").scaled(50,50));
    ui->super_2->hide();
    ui->clone->setPixmap(QPixmap(":/pics/clone").scaled(50,50));
    ui->clone->hide();

    //the start plat
    platptr = &platstart;
    platptr->generate(-50,650);
    platptr->setPixmap(QPixmap(":/pics/plat").scaled(600,50));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(platptr));

    //generate normal plat form
    for (int i=0;i<10;i++){
        platptr = &platA[i];
        platptr->generate(qrand()%500,75+i*65);
        platptr->setPixmap(QPixmap(":/pics/plat").scaled(90,20));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(platptr));
    }
    //generate platform 2
    for (int i=0;i<2;i++){
        renew:
        haveplat = false;
        platptr = &platB[i];
        platptr->generate(qrand()%500,220*i);
        platptr->setPixmap(QPixmap(":/pics/plat2").scaled(70,30));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(platptr));
        for (int k=0;k<10;k++){
            platptrformer =  &platA[k];
            haveplat = static_cast<plat2*>(platptr)->collide_plat(platptrformer);
            if (haveplat){
                scene->removeItem(platptr);
                goto renew;
            }
        }
    }

    //generate monster
    monster = new QGraphicsPixmapItem();
    monster->setPixmap(QPixmap(":/pics/mashroom").scaled(60,60));
    monster->setPos(qrand()%440,150);
    scene->addItem(monster);

    ui->gameover->hide();
    connect(role,SIGNAL(stop_game()),this,SLOT(gameover()));

    //generate clon
    clone = new QGraphicsPixmapItem();
    clone->setPixmap(QPixmap(":/pics/clone").scaled(40,40));
    clone->setPos(qrand()%450,100);
    scene->addItem(clone);

    //generate super
    super = new QGraphicsPixmapItem();
    super->setPixmap(QPixmap(":/pics/super").scaled(40,40));
    super->setPos(qrand()%450,50);
    scene->addItem(super);

    //generate blackmage
    blackmage = new QGraphicsPixmapItem();
    blackmage->setPixmap(QPixmap(":/pics/blackmage").scaled(100,150));
    blackmage->setPos(qrand()%400,-250);
    scene->addItem(blackmage);

    //generate maple new
    maple = new QGraphicsPixmapItem();
    maple->setPixmap(QPixmap(":/pics/maple").scaled(50,30));
    maple->setPos(qrand()%450,300);
    scene->addItem(maple);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//control the role go left and right
void MainWindow::keyPressEvent(QKeyEvent *e){
    switch(e->key()){
    case Qt::Key_A:
        if(is_play){
            role->setPos(role->x()-4,role->y());
            if(role->x()<=-25)
                role->setPos(475,role->y());
        }
        break;
    case Qt::Key_D:
        if (is_play){
            role->setPos(role->x()+4,role->y());
            if(role->x()>=480)
                role->setPos(-25,role->y());
        }
        break;
    }
};

// shoot bullets
void MainWindow::mousePressEvent(QMouseEvent *e){
    if (is_play){
        if (role->isclone){
            bullet *b[3];

            for (int i=0;i<3;i++){
                b[i]=new bullet;
                b[i]->get_is_play(is_play);
                b[i]->setPixmap(QPixmap(":/pics/bullet").scaled(50,50));
                b[i]->setPos(role->x() + role->pixmap().width()/2 - b[i]->pixmap().width()/2 , role->y() - b[i]->pixmap().height());
                switch (i) {
                case 0:
                    b[i]->connect(this, SIGNAL(bfly(QGraphicsPixmapItem* ,QGraphicsScene*)), b[i], SLOT(left(QGraphicsPixmapItem* ,QGraphicsScene*)));
                    break;
                case 1:
                    b[i]->connect(this, SIGNAL(bfly(QGraphicsPixmapItem* ,QGraphicsScene*)), b[i], SLOT(up(QGraphicsPixmapItem* ,QGraphicsScene*)));
                    break;
                case 2:
                    b[i]->connect(this, SIGNAL(bfly(QGraphicsPixmapItem* ,QGraphicsScene*)), b[i], SLOT(right(QGraphicsPixmapItem* ,QGraphicsScene*)));
                    break;

                }
                scene->addItem(static_cast<QGraphicsPixmapItem*>(b[i]));
            }
        }
        else{
            bullet *b = new bullet;
            b->get_is_play(is_play);
            b->setPixmap(QPixmap(":/pics/bullet").scaled(50,50));
            b->setPos(role->x() + role->pixmap().width()/2 - b->pixmap().width()/2 , role->y() - b->pixmap().height());
            b->connect(this, SIGNAL(bfly(QGraphicsPixmapItem* ,QGraphicsScene*)), b, SLOT(up(QGraphicsPixmapItem* ,QGraphicsScene*)));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e){
    switch(e->key()){
    case Qt::Key_A:
        if(is_play){
            role->setPos(role->x()-4,role->y());
            if(role->x()<=-25)
                role->setPos(475,role->y());
        }
        break;
    case Qt::Key_D:
        if (is_play){
            role->setPos(role->x()+4,role->y());
            if(role->x()>=480)
                role->setPos(-25,role->y());
        }
        break;
    }
}

void MainWindow::on_start_clicked()
{
    is_play=true;
    role->get_is_play(is_play);
    role->connect(this, SIGNAL(rolejump(QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,int* )), role, SLOT(jump(QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,int *)));
    connect(this,SIGNAL(rolejump(QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,QGraphicsPixmapItem*,int *)),this,SLOT(set_role_v()));
    ui->start->hide();
    ui->stop->show();
    Timer1 = startTimer(1000/60);
    TimerJumpAgain = startTimer(10);
    TimerGodown = startTimer(1000/120);
    connect(this,SIGNAL(judge()),this,SLOT(judge_collide()));
    connect(this,SIGNAL(jump_again()),role,SLOT(jump_again()));
    platptr = &platB[0];
    static_cast<plat2*>(platptr)->connect(this,SIGNAL(platMove(bool)),static_cast<plat2*>(platptr),SLOT(move(bool)));
    platptr = &platB[1];
    static_cast<plat2*>(platptr)->connect(this,SIGNAL(platMove(bool)),static_cast<plat2*>(platptr),SLOT(move(bool)));
}

void MainWindow::on_stop_clicked()
{
    if (is_play){
        ui->stop->setText("restart");
        is_play=false;
        role->get_is_play(is_play);
    }
    else{
        ui->stop->setText("stop");
        is_play=true;
        role->get_is_play(is_play);
    }

}

//control all the things that need time
void MainWindow::timerEvent(QTimerEvent *e){
    if(e->timerId() == Timer1){
        ui->scorenum->setNum(score);
        emit rolejump(monster,clone,super,blackmage,maple,&score);
        if (role->shield)
            ui->super_2->show();
        else {
            ui->super_2->hide();
        }
        if (role->isclone)
            ui->clone->show();
        else {
            ui->clone->hide();
        }
        emit bfly(monster,scene);
        emit platMove(is_play);
    }
    if (e->timerId() == TimerJumpAgain)
        emit judge();
    if(e->timerId() == TimerGodown){
        emit itemgodown_signal(this,distance);
        emit godown_signal(monster,distance,0);
        emit godown_signal1(clone,distance,1);
        emit godown_signal2(super,distance,2);
        emit godown_signal3(blackmage,distance,3);
        emit godown_signal4(maple,distance,4);
    }
};

/* check if the role touch any plat,  while the role going down
 * if true
 * all things go down by [ 650-(plat->y()) ]
 */
void MainWindow::judge_collide(){
    platptr = &platstart;
    isCollide_start = role->collidesWithItem(platptr);
    if(isCollide_start == true && is_play){
        emit jump_again();
        isCollide = false;
        isCollide_start = false;
        return;
    }
    for (int i=0;i<12;i++){
        if(i<10){
            platptr = &platA[i];
        }
        if(i>9){
            platptr = &platB[i-10];
        }
        if (role_v < 0){
            isCollide = platptr->collide_judge(role);
        }
        if ((isCollide == true)&&is_play){
            emit jump_again();
            //new - plat go down
            distance = 600 - static_cast<QGraphicsPixmapItem*>(platptr)->y();
            if (distance>0){
                score+=distance;
            for (int j=0;j<12;j++){
                if (j<10)
                    platptr = &platA[j];
                if (j>9)
                    platptr = &platB[j-10];
                connect(this,SIGNAL(itemgodown_signal(QWidget*,double)),platptr,SLOT(godown(QWidget*,double)));
            }
            connect(this,SIGNAL(godown_signal(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            connect(this,SIGNAL(godown_signal1(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            connect(this,SIGNAL(godown_signal2(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            connect(this,SIGNAL(godown_signal3(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            connect(this,SIGNAL(godown_signal4(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            platptr=&platstart;
            platptr->setY(static_cast<QGraphicsPixmapItem*>(platptr)->y()+distance+700);
        isCollide = false;
        isCollide_start = false;
        return;
            }
        }
    }
}

void MainWindow::set_role_v(){
    role_v = role->get_v();
}

//finish game
void MainWindow::gameover(){
    is_play=false;
    ui->gameover->show();
    ui->stop->hide();
    ui->scorenum->hide();
    ui->SCORE->hide();
    ui->final_score->setNum(score);
    ui->final_score->show();
}

//make all items going down except platforms
void MainWindow::godown(QGraphicsPixmapItem *it,double distance,int k){
    if(c[k]*2<distance){
        it->setY(it->y()+2);
        c[k]++;
        if (it->y()>=700)
            it->setPos(qrand()%400,-200-qrand()%300);
        else if (it->y()>700 && (k==0||k==3)){
            it->setPos(qrand()%400,-700-qrand()%300);
        }
    }
    else if (c[k]*2>=static_cast<int>(distance)){
        c[k]=0;
        switch(k){
        case 0:
            disconnect(this,SIGNAL(godown_signal(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            break;
        case 1:
            disconnect(this,SIGNAL(godown_signal1(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            break;
        case 2:
            disconnect(this,SIGNAL(godown_signal2(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            break;
        case 3:
            disconnect(this,SIGNAL(godown_signal3(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            break;
        case 4:
            disconnect(this,SIGNAL(godown_signal4(QGraphicsPixmapItem *,double,int)),this,SLOT(godown(QGraphicsPixmapItem *,double,int )));
            break;
        }
    }
}
