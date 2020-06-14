#include "place.h"
#include "ui_place.h"
#include "elf.h"

Place::Place(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->show();
    ui->rock->hide();
    ui->ice->hide();
    ui->grass->hide();
    ui->cancel1->hide();
    connect(ui->button,&QPushButton::clicked,this,&Place::build);
    //鼠标移上去变手
    ui->cancel1->setCursor(QCursor(Qt::PointingHandCursor));
    ui->grass->setCursor(QCursor(Qt::PointingHandCursor));
    ui->ice->setCursor(QCursor(Qt::PointingHandCursor));
    ui->rock->setCursor(QCursor(Qt::PointingHandCursor));
    ui->button->setCursor(QCursor(Qt::PointingHandCursor));
}
Place::~Place(){
    delete ui;
}
void Place::build(){
    ui->rock->show();
    ui->ice->show();
    ui->grass->show();
    ui->cancel1->show();
    ui->button->hide();
}
//点击一级取消键
void Place::on_cancel1_clicked()
{
    ui->rock->hide();
    ui->ice->hide();
    ui->grass->hide();
    ui->cancel1->hide();
    ui->button->show();
}
//点击二级取消键
//决定移植此功能到选项类中
/*void Place::on_cancel2_clicked()
{
    ui->sell->hide();
    ui->up->hide();
    ui->cancel2->hide();
}
*/

//小石怪类
void Place::on_rock_clicked()
{
    emit build_rock(this->x()+90,this->y()+80);
    ui->rock->hide();
    ui->ice->hide();
    ui->grass->hide();
    ui->cancel1->hide();
}
