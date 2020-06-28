#include "bullet.h"

Bullet::Bullet(QObject *parent):
    QObject(parent)
{
    speed = 30;
    damage = 30;
    hit_state = false;
    ice = false;
}
//绘制子弹
void Bullet::draw(QPainter*painter){
    painter->save();
    painter->drawPixmap(current_point,pixmap);
    painter->restore();
}
//子弹移动
void Bullet::move(){
    if(cast_object){//如果发射对象存在
        //击中目标对象
        if(collision(current_point,10,target_point,10)){
            hit_state = true;
            return;
        }
        target_point = target_object->get_current_pos();
        QVector2D normalized(target_point - current_point);
        normalized.normalize();
        current_point = current_point + normalized.toPoint() * speed;
    }
}
//设置发射对象
void Bullet::set_cast_object(Object *o){
    cast_object = o;
    start_point = cast_object->get_current_pos();
}
//子弹击中目标
void Bullet::hitTarget(){
    target_object->getDamage(damage,ice);
}
