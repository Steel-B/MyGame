#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //返回主菜单
    connect(&Subw,&SubWidget::Backmenu,this,&MainWidget::dealBack);
    connect(&Subw,&SubWidget::to_map,this,&MainWidget::dealmap);
    ui->Begin->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Exit->setCursor(QCursor(Qt::PointingHandCursor));

    playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/sound/sound/BGM/StudioEIM - 神木村 LeafreInMirror.mp3"));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    //qDebug()<<"music should be played";
    //player->setMedia(QUrl("qrc::/sound/sound/BGM/StudioEIM - 神木村 LeafreInMirror.mp3"));
    player->setVolume(30);
    player->play();
}
MainWidget::~MainWidget()
{
    delete ui;
    delete playlist;
    delete player;
}
//绘制背景图
void MainWidget::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("images/menu/Menu.png"));
}
//进入关卡选择页面
void MainWidget::on_Begin_clicked()
{
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();
    Subw.setParent(this);
    Subw.show();
}
//返回主菜单
void MainWidget::dealBack(){
    ui->Begin->show();
    ui->Exit->show();
    Subw.hide();
    playlist->addMedia(QUrl("qrc:/sound/sound/BGM/StudioEIM - 神木村 LeafreInMirror.mp3"));
    player->setPlaylist(playlist);
    player->play();
}

void MainWidget::dealmap(){
    qDebug()<<"music should stop";
    playlist->clear();
}

void MainWidget::on_Exit_clicked()
{
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();
    QTimer::singleShot(500,this,SLOT(close()));
}
