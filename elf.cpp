#include "elf.h"
#include "ui_option.h"



Option::Option(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
    connect(ui->cancel2,&QPushButton::clicked,this,&Option::hide);
    //鼠标变手
    ui->cancel2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->up->setCursor(QCursor(Qt::PointingHandCursor));
    ui->sell->setCursor(QCursor(Qt::PointingHandCursor));
}
Option::~Option(){
    delete ui;
}


Elf::Elf(Object *parent) :
    Object(parent)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
    connect(this,&Elf::clicked,&opt,&Option::show);
}
Elf::~Elf(){
}

Rock::Rock(Elf *parent):
    Elf(parent)
{
    this->setStyleSheet(tr("border-image: url(:/images/images/elf/rock1.png);"));
}
Rock::paintEvent(){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0,0,300,300,QPixmap(":/images/images/elf/rock1.png"));
}
Rock::~Rock(){

}
