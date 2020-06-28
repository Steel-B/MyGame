#include "subwidget.h"
#include "ui_subwidget.h"


SubWidget::SubWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubWidget)
{
    ui->setupUi(this);
    //关卡选择页面点击返回
    connect(&back,&QPushButton::clicked,this,&SubWidget::on_back_clicked);
    ui->b1->setCursor(QCursor(Qt::PointingHandCursor));
    ui->b2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->b3->setCursor(QCursor(Qt::PointingHandCursor));
    ui->back->setCursor(QCursor(Qt::PointingHandCursor));
}
SubWidget::~SubWidget(){
}
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

    map1 = new Map1;
    emit to_map1();
    map1->setParent(parentWidget());
    map1->show();
    //关卡页面点击返回
    connect(map1,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//进入关卡2
void SubWidget::on_b2_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    map2 = new Map2;
    emit to_map1();
    map2->setParent(parentWidget());
    map2->show();
    //关卡页面点击返回
    connect(map2,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//进入关卡3
void SubWidget::on_b3_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    map3 = new Map3;
    emit to_map1();
    map3->setParent(parentWidget());
    map3->show();
    //关卡页面点击返回
    connect(map3,&Map::Backsub,this,&SubWidget::dealBacksub);
}
//退出游戏返回关卡选择页面
void SubWidget::dealBacksub(Map* map){
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();
    delete map;
}

