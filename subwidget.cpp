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
    emit Backmenu();
}
//进入关卡一
void SubWidget::on_b1_clicked()
{
    map1 = new Map1;
    emit to_map1();
    map1->setParent(parentWidget());
    map1->show();
    //关卡页面点击返回
    connect(map1,&Map1::Backsub,this,&SubWidget::dealBacksub);
}
//退出游戏返回关卡选择页面
void SubWidget::dealBacksub(){
    qDebug()<<"signal was dealed";
    delete map1;
}
