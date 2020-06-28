#include "object.h"


Object::Object(QPushButton *parent) ://创建对象,设置血量，获得位置
    QPushButton(parent),
    attack_range(0)
{
    attack_ablt = true;
    ice = false;
    freeze = false;
    this->setCursor(QCursor(Qt::PointingHandCursor));
}
Object::~Object(){
}
//设置满血量
void Object::set_max_blood(int max){
    max_blood = max;
    current_blood = max;
}

//对象受到伤害
void Object::getDamage(int damage,bool ice){
    current_blood-=damage;
    //如果子弹有减速属性,且该对象没有被冰冻
    if(ice&&!freeze){
        change_state();
        freezed();
    }
}
//对象攻击冷却
void Object::cooldown(){
    QTimer::singleShot(CD_time,this,SLOT(change_attack_ablt()));
}

void Object::draw(QPainter *painter,bool map3){
    static const int Health_Bar_Width = 20;
    painter->save();

    if(!map3){//如果不是第三关，则绘制攻击范围
        painter->setPen(Qt::white);
        painter->setBrush(Qt::NoBrush);
        if(attack_range>100)painter->drawEllipse(pos()+QPoint(20,20),attack_range-10,attack_range-10);
    }

    painter->drawPixmap(get_current_pos(),pixmap);
    painter->setPen(Qt::black);
    QPoint healthBarPoint = get_current_pos() + QPoint(15 + (pixmap.width()- 50)/2, -height() / 6);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)get_current_blood() / get_max_blood() * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);

    painter->restore();
}

//设置初始速度
void Object::set_speed(double sp){
    move_speed = sp;
    low_move_speed = sp/2.0;
}

//对象被冷冻
void Object::freezed(){
    QTimer::singleShot(4000,this,SLOT(change_state()));
}
//改变状态（正常/冷冻）
void Object::change_state(){
    QPixmap tmp1 = pixmap;
    pixmap = freezed_pix;
    freezed_pix = tmp1;
    double tmp2 = move_speed;
    move_speed = low_move_speed;
    low_move_speed = tmp2;
    freeze = !freeze;
}

