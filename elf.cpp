#include "elf.h"
#include "ui_option.h"



Option::Option(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
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
    //点击防御塔显示选项界面
    connect(this,&Elf::clicked,this,&Elf::option_show);
}
Elf::~Elf(){
}
//显示选项页面
void Elf::option_show(){
    opt = new Option;
    connect(opt,SIGNAL(sell()),this,SLOT(sell()));
    connect(opt,SIGNAL(up()),this,SLOT(up_signal_emit()));
    opt->setParent(this->parentWidget());
    opt->move(get_current_pos()+QPoint(-80,-85)+QPoint((pixmap.width()-pixmap1.width())/2,(pixmap.height()-pixmap1.height())/2));
    opt->show();
}
//出售防御塔
void Elf::sell(){
    emit sell_signal(this);
    delete opt;
}
//发出升级信号
void Elf::up_signal_emit(){
    //三级以下才能升级
    if(level < 3)emit up_signal(this);
    delete opt;
}
//防御塔升级（虚函数）
void Elf::up(){}

Rock::Rock(Elf *parent):
    Elf(parent)
{
    level = 1;
    resize(70,70);      //图片大小
    set_damage(30);     //攻击伤害
    set_CD_time(3000);  //攻击冷却时间
    set_range(150);     //攻击范围
    set_max_blood(100); //血量
    set_cost(70);       //建造花费
    pixmap1 = QPixmap(":/images/images/elf/rock1.png");
    pixmap2 = QPixmap(":/images/images/elf/rock2.png");
    pixmap3 = QPixmap(":/images/images/elf/rock3.png");
    pixmap = pixmap1;
    set_pixmap(pixmap1);               //精灵图片
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/rock(S).png"));  //子弹图片
}
Rock::~Rock(){
}
//一类防御塔升级
void Rock::up(){
    if(level == 3)return;
    if(level == 1){
        set_current_pos(get_current_pos()-QPoint((pixmap2.width()-pixmap1.width())/2,pixmap2.height()-pixmap1.height()));
        pixmap = pixmap2;
        set_pixmap(pixmap2);
        set_max_blood(120);
        set_range(180);
        set_CD_time(2500);
        set_damage(45);
    }
    if(level == 2){
        set_current_pos(get_current_pos()-QPoint((pixmap3.width()-pixmap2.width())/2,pixmap3.height()-pixmap2.height()));
        pixmap = pixmap3;
        set_pixmap(pixmap3);
        set_max_blood(150);
        set_range(230);
        set_CD_time(2000);
        set_damage(60);
    }
    level++;
}
Ice::Ice(Elf *parent):
    Elf(parent)
{
    level = 1;
    resize(70,70);
    set_damage(25);
    set_CD_time(3000);
    set_range(150);
    set_max_blood(100);
    set_cost(100);       //建造花费
    set_ice();
    pixmap1 = QPixmap(":/images/images/elf/ice1.png");
    pixmap2 = QPixmap(":/images/images/elf/ice2.png");
    pixmap3 = QPixmap(":/images/images/elf/ice3.png");
    pixmap = pixmap1;
    set_pixmap(pixmap1);               //精灵图片
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/ice.png"));
}
Ice::~Ice(){
}
//二类防御塔升级
void Ice::up(){
    if(level == 3)return;
    if(level == 1){
        set_current_pos(get_current_pos()-QPoint((pixmap2.width()-pixmap1.width())/2,pixmap2.height()-pixmap1.height()));
        pixmap = pixmap2;
        set_pixmap(pixmap2);
        set_max_blood(130);
        set_range(200);
        set_CD_time(2500);
        set_damage(35);
    }
    if(level == 2){
        set_current_pos(get_current_pos()-QPoint((pixmap3.width()-pixmap2.width())/2,pixmap3.height()-pixmap2.height()));
        pixmap = pixmap3;
        set_pixmap(pixmap3);
        set_max_blood(150);
        set_range(230);
        set_CD_time(2000);
        set_damage(50);
    }
    level++;
}
Grass::Grass(Elf *parent):
    Elf(parent)
{
    level = 1;
    resize(70,70);
    set_damage(10);
    set_CD_time(700);
    set_range(170);
    set_max_blood(100);
    set_cost(120);       //建造花费
    pixmap1 = QPixmap(":/images/images/elf/grass1.png");
    pixmap2 = QPixmap(":/images/images/elf/grass2.png");
    pixmap3 = QPixmap(":/images/images/elf/grass3.png");
    pixmap = pixmap1;
    set_pixmap(pixmap1);               //精灵图片
    set_bullet_pix(QPixmap(":/images/images/elf/bullet/bubble.png"));
}
Grass::~Grass(){
}
//三类防御塔升级
void Grass::up(){
    if(level == 3)return;
    if(level == 1){
        set_current_pos(get_current_pos()-QPoint((pixmap2.width()-pixmap1.width())/2,pixmap2.height()-pixmap1.height()));
        pixmap = pixmap2;
        set_pixmap(pixmap2);
        set_max_blood(150);
        set_range(200);
        set_CD_time(500);
        set_damage(15);
    }
    if(level == 2){
        set_current_pos(get_current_pos()-QPoint((pixmap3.width()-pixmap2.width())/2,pixmap3.height()-pixmap2.height()));
        pixmap = pixmap3;
        set_pixmap(pixmap3);
        set_max_blood(200);
        set_range(250);
        set_CD_time(300);
        set_damage(20);
    }
    level++;
}



