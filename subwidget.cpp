#include "subwidget.h"
#include "ui_subwidget.h"


SubWidget::SubWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubWidget)
{
    ui->setupUi(this);
    //关卡选择页面点击返回
    ui->b1->setCursor(QCursor(Qt::PointingHandCursor));
    ui->b2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->b3->setCursor(QCursor(Qt::PointingHandCursor));
    ui->back->setCursor(QCursor(Qt::PointingHandCursor));
}
SubWidget::~SubWidget(){}
//返回主菜单
void SubWidget::on_back_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    emit Backmenu();
}
//进入关卡一
void SubWidget::on_b1_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    map = new Map1;
    emit to_map();
    map->setParent(parentWidget());
    map->show();
    //关卡页面点击返回
    connect(map,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//进入关卡2
void SubWidget::on_b2_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    map = new Map2;
    emit to_map();
    map->setParent(parentWidget());
    map->show();
    //关卡页面点击返回
    connect(map,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//进入关卡3
void SubWidget::on_b3_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    map = new Map3;
    emit to_map();
    map->setParent(parentWidget());
    map->show();
    //关卡页面点击返回
    connect(map,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//退出游戏返回关卡选择页面
void SubWidget::dealBacksub(Map* map){
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();
    delete map;
}

