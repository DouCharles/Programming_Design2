#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QCursor>
#include <QMediaPlayer>
#include "lv1.h"
#include "chooselv.h"
#include "choosechar.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_chooselv_clicked();

    void on_choosechar_clicked();

    void musicstop();

private:
    Ui::MainWindow *ui;
    QCursor cursor;
    QMediaPlayer *player;
    LV1 *lv_1 = new LV1;
    chooselv *choose_lv = new chooselv;
    choosechar *choose_char = new choosechar;
};

#endif // MAINWINDOW_H
