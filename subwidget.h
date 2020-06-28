#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QMediaPlayer>
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
signals:
    void Backmenu();
    void to_map1();
    void to_map2();
    void to_map3();
public slots:
    void dealBacksub(Map*);
private slots:
    void on_back_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

private:
    Ui::SubWidget *ui;
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton back;
    Map1 *map1;
    Map2 *map2;
    Map3 *map3;
};

#endif // SUBWIDGET_H
