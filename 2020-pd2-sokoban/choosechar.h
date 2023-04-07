#ifndef CHOOSECHAR_H
#define CHOOSECHAR_H

#include <QDialog>
#include <QCursor>
#include "lv1.h"
namespace Ui {
class choosechar;
}

class choosechar : public QDialog
{
    Q_OBJECT

public:
    explicit choosechar(QWidget *parent = nullptr);
    ~choosechar();

signals:
    void musicstop_signal();

private slots:
    void on_char1_clicked();

    void on_char2_clicked();

    void on_char3_clicked();

    void on_char4_clicked();


private:
    Ui::choosechar *ui;
    QCursor cursor;
    LV1 *lv_1 = new LV1;
};

#endif // CHOOSECHAR_H
