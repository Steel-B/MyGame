#include "object.h"


Object::Object(QPushButton *parent) ://创建对象,设置血量，获得位置
    QPushButton(parent),
    center_pos(x()+width()/2,y()+height()*3/4),
    attack_range(0)
{
}
Object::~Object(){
    //delete ui_ob;
}
//设置满血量
void Object::set_max_blood(int max){
    this->max_blood = max;
    this->current_blood = max;
}
//设置当前血量
void Object::set_now_blood(int n){
    this->current_blood = n;
}
//获取当前血量
int Object::get_now_blood(){
    return this->current_blood;
}
int Object::get_max_blood(){
    return this->current_blood;
}
//设置攻击范围
void Object::set_range(int rg){
    this->attack_range = rg;
}

//绘制血条
void Object::drawblood(QPainter *painter){
    static const int Health_Bar_Width = 20;
    painter->save();
    QPoint healthBarPoint(this->width()/3,this->height()/2 - 10);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)current_blood / max_blood * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);
    // 绘制偏转坐标,由中心+偏移=左上
/*    static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    painter->translate(m_pos);
    painter->rotate(m_rotationSprite);
    // 绘制敌人
    painter->drawPixmap(offsetPoint, m_sprite);
    */
    painter->restore();
}
//对象受到伤害
void Object::getDamage(int damage){
    current_blood-=damage;
    if(current_blood<=0){
        this->~Object();
    }
}
