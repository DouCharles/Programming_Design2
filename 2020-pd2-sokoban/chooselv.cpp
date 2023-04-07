#include "chooselv.h"
#include "ui_chooselv.h"
#include <QPixmap>

chooselv::chooselv(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::chooselv)
{
    ui->setupUi(this);
    //control the size of thewindow
    Qt::WindowFlags size = nullptr;
    size |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(size);
    setFixedSize(800, 600);

    // set up the background
    this->setAutoFillBackground(true);
    QPalette bg = this->palette();
    bg.setBrush(QPalette::Window,
                QBrush(QPixmap(":/image/chooselv").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(bg);

    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
}

chooselv::~chooselv()
{
    delete ui;
}

void chooselv::on_level1_clicked()
{
    this->hide();
    lv_1->timer->start(1000);
    lv_1->show();
    lv_1->player->play();
    emit stopmusic_signal();
}

void chooselv::on_level2_clicked()
{
    this->hide();
    lv_2->show();
    lv_2->timer->start(1000);
    lv_2->player->play();
    emit stopmusic_signal();
}
