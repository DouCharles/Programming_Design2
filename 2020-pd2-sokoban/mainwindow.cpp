#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
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
                QBrush(QPixmap(":/image/login").scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(bg);

    //set up  the cursor
    QPixmap cursorpic(":/image/hand");
    QSize cSize(25,25);
    QPixmap CScal = cursorpic.scaled(cSize, Qt::KeepAspectRatio);
    cursor = QCursor(CScal);
    this->setCursor(cursor);

    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/image/loginmusic"));
    player->setVolume(80);
    player->play();

    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(choose_char,SIGNAL(musicstop_signal()),this,SLOT(musicstop()));
    connect(choose_lv,SIGNAL(stopmusic_signal()),this,SLOT(musicstop()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    this->hide();
    lv_1->show();
    player->stop();
    lv_1->player->play();
    lv_1->timer->start(1000);
}

void MainWindow::on_chooselv_clicked()
{
    this->hide();
    choose_lv->show();
}

void MainWindow::on_choosechar_clicked()
{
    this->hide();
    choose_char->show();
}

void MainWindow::musicstop()
{
    player->stop();
}
