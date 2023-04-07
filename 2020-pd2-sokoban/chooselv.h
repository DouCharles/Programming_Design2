#ifndef CHOOSELV_H
#define CHOOSELV_H

#include <QDialog>
#include "lv1.h"
#include "lv2.h"

namespace Ui
{
    class chooselv;
}

class chooselv : public QDialog
{
    Q_OBJECT

public:
    explicit chooselv(QWidget *parent = nullptr);
    ~chooselv();

signals:
    void stopmusic_signal();

private slots:
    void on_level1_clicked();

    void on_level2_clicked();

private:
    Ui::chooselv *ui;
    LV1 *lv_1 = new LV1;
    LV2 *lv_2 = new LV2;
};

#endif // CHOOSELV_H
