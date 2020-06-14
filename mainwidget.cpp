#include "mainwidget.h"
#include "ui_Mainwidget.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //返回主菜单
    connect(&Subw,&SubWidget::Backmenu,this,&MainWidget::dealBack);
    //connect(&Subw,&SubWidget::to_map1,this,&MainWidget::dealmap1);
    ui->Begin->setCursor(QCursor(Qt::PointingHandCursor));
    ui->Exit->setCursor(QCursor(Qt::PointingHandCursor));
}
MainWidget::~MainWidget()
{
    delete ui;
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
    Subw.setParent(this);
    Subw.show();
}
//返回主菜单
void MainWidget::dealBack(){
    ui->Begin->show();
    ui->Exit->show();
    Subw.hide();
}
/*
void MainWidget::dealmap1(){

}*/
