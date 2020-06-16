#include "bullet.h"

Bullet::Bullet(QObject *parent):
    QObject(parent)
{
    //pixmap = QPixmap(":/images/images/elf/bullet/rock(S).png");
    speed = 15;
    damage = 80;
    hit_state = false;
}
//绘制子弹
void Bullet::draw(QPainter*painter){
    painter->save();
    painter->drawPixmap(current_point,pixmap);
    painter->restore();
}
//子弹移动
void Bullet::move(){
    qDebug()<<"the target point is "<<"("<<target_point.x()<<","<<target_point.y()<<")";
    if(collision(current_point,10,target_point,10)){
        hitTarget();
        hit_state = true;
        return;
    }
    target_point = target_object->get_current_pos();
    QVector2D normalized(target_point - current_point);
    normalized.normalize();
    current_point = current_point + normalized.toPoint() * speed;
}
//设置发射对象
void Bullet::set_cast_object(Object *o){
    cast_object = o;
    start_point = cast_object->get_current_pos();
}
//获取发射对象
Object* Bullet::get_cast_object(){
    return cast_object;
}
//设置目标对象
void Bullet::set_target_object(Object *o){
    target_object = o;
}
//设置子弹当前位置
void Bullet::set_current(QPoint pos){
    current_point = pos;
}
//返回子弹当前位置
QPoint Bullet::current_pos(){
    return current_point;
}
//返回子弹初始位置
QPoint Bullet::start_pos(){
    return start_point;
}
QPoint Bullet::target_pos(){
    return target_point;
}
//子弹击中目标
void Bullet::hitTarget(){
    target_object->getDamage(damage);
}
bool Bullet::get_state(){
    return hit_state;
}
void Bullet::set_pixmap(QPixmap p){
    pixmap = p;
}
