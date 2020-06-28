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
//关卡选择页面
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    ~SubWidget();
signals:
    void Backmenu();    //返回主页面
    void to_map();      //进入关卡
public slots:
    void dealBacksub(Map*); //退出关卡
private slots:
    //返回主页面按钮
    void on_back_clicked();
    //关卡按钮
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();

private:
    Ui::SubWidget *ui;
    Map *map;
};

#endif // SUBWIDGET_H
