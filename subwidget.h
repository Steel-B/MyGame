#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include "map.h"

namespace Ui {
class SubWidget;
}
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    ~SubWidget();
    void dealBacksub();
signals:
    void Backmenu();
    void to_map1();
    void to_map2();
    void to_map3();
public slots:

private slots:
    void on_back_clicked();

    void on_b1_clicked();

private:
    Ui::SubWidget *ui;
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton back;
    Map1 map1;
    Map map2;
    Map map3;
};

#endif // SUBWIDGET_H
