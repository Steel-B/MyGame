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
    //connect(this,&Elf::clicked,this,&Elf::set_option);
    connect(this,&Elf::clicked,&opt,&Option::show);
    //setWindowFlags(Qt::WindowStaysOnTopHint);
}
Elf::~Elf(){
}
void Elf::up(){}
Rock::Rock(Elf *parent):
    Elf(parent)
{
    resize(70,70);
    set_damage(30);
    set_CD_time(3000);
    set_range(200);
    set_max_blood(100);
    set_pixmap(QPixmap(":/images/images/elf/rock1.png"));
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/rock(S).png"));
}
Rock::~Rock(){
}
Ice::Ice(Elf *parent):
    Elf(parent)
{
    resize(70,70);
    set_damage(25);
    set_CD_time(3000);
    set_range(200);
    set_max_blood(100);
    set_ice();
    set_pixmap(QPixmap(":/images/images/elf/ice1.png"));
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/ice.png"));
}
Ice::~Ice(){
}
Grass::Grass(Elf *parent):
    Elf(parent)
{
    resize(70,70);
    set_damage(10);
    set_CD_time(500);
    set_range(200);
    set_max_blood(100);
    set_pixmap(QPixmap(":/images/images/elf/grass1.png"));
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/bubble.png"));
}
Grass::~Grass(){
}
/*
void Option::on_cancel2_clicked()
{

}
*/
