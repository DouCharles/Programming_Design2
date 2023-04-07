#include "choosechar.h"
#include "ui_choosechar.h"


choosechar::choosechar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosechar)
{
    ui->setupUi(this);
    //control the size of the window
    Qt::WindowFlags size = nullptr;
    size |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(size);
    setFixedSize(800, 600);

    // set up the background
    this->setAutoFillBackground(true);
    QPalette bg = this->palette();
    bg.setBrush(QPalette::Window,
                QBrush(QPixmap(":/image/chooserole").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(bg);

    //set up  the cursor
    QPixmap cursorpic(":/image/hand");
    QSize cSize(25,25);
    QPixmap CScal = cursorpic.scaled(cSize, Qt::KeepAspectRatio);
    cursor = QCursor(CScal);
    this->setCursor(cursor);
    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));

    QPixmap manpic(":/image/person");
    QPixmap man2pic(":/image/person2");
    QPixmap man3pic(":/image/person3");
    QPixmap man4pic(":/image/person4");

    ui->char1->setIcon(manpic);
    ui->char1->setIconSize(ui->char1->size());
    ui->char2->setIcon(man2pic);
    ui->char2->setIconSize(ui->char2->size());
    ui->char3->setIcon(man3pic);
    ui->char3->setIconSize(ui->char3->size());
    ui->char4->setIcon(man4pic);
    ui->char4->setIconSize(ui->char4->size());
}

choosechar::~choosechar()
{
    delete ui;
}
void choosechar::on_char1_clicked()
{
    this->hide();
    QPixmap manpic(":/image/person");
    lv_1->man->setPixmap((manpic.scaled(lv_1->man->width(), lv_1->man->height(), Qt::KeepAspectRatio)));
    lv_1->player->play();
    lv_1->show();
    lv_1->charindex=1;
    lv_1->timer->start(1000);
    emit musicstop_signal();
}

void choosechar::on_char2_clicked()
{
    this->hide();
    QPixmap man2pic(":/image/person2");
    lv_1->man->setPixmap((man2pic.scaled(lv_1->man->width(), lv_1->man->height(), Qt::KeepAspectRatio)));
    lv_1->player->play();
    lv_1->show();
    lv_1->charindex=2;
    lv_1->timer->start(1000);
    emit musicstop_signal();
}

void choosechar::on_char3_clicked()
{
    this->hide();
    QPixmap man3pic(":/image/person3");
    lv_1->man->setPixmap((man3pic.scaled(lv_1->man->width(), lv_1->man->height(), Qt::KeepAspectRatio)));
    lv_1->player->play();
    lv_1->show();
    lv_1->charindex=3;
    lv_1->timer->start(1000);
    emit musicstop_signal();
}

void choosechar::on_char4_clicked()
{
    this->hide();
    QPixmap man4pic(":/image/person4");
    lv_1->man->setPixmap((man4pic.scaled(lv_1->man->width(), lv_1->man->height(), Qt::KeepAspectRatio)));
    lv_1->player->play();
    lv_1->show();
    lv_1->charindex=4;
    lv_1->timer->start(1000);
    emit musicstop_signal();
}
