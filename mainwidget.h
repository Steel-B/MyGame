#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QDebug>
#include "subwidget.h"

namespace Ui {
class MainWidget;
}
//主页面
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void paintEvent(QPaintEvent *);     //绘制函数
public slots:
    void dealBack();            //从关卡选择页面返回主页面
    void dealmap();             //进入关卡，更换BGM
private slots:
    void on_Begin_clicked();    //进入关卡选择页面
    void on_Exit_clicked();     //退出游戏
private:
    Ui::MainWidget *ui;
    SubWidget Subw;             //关卡选择页面
    QMediaPlaylist *playlist;   //BGM列表
    QMediaPlayer *player;
};

#endif // WIDGET_H
