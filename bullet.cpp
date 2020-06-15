#include "bullet.h"

Bullet::Bullet(QObject *parent):
    QObject(parent)
{
    pixmap = QPixmap(":/images/images/elf/bullet/rock(S).png");
    speed = 3;
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
    /*static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this,"current_point");
    animation->setDuration(duration);
    animation->setStartValue(start_point);
    animation->setEndValue(target_point);
    connect(animation,SIGNAL(finished()),this,SLOT(hitTarget()));*/
    if(collision(current_point,5,target_point,5)){
        hitTarget();
        hit_state = true;
        return;
    }
    target_point = target_object->get_current_pos();
    QVector2D normalized(target_point - current_point);
    normalized.normalize();
    current_point = current_point + normalized.toPoint() * speed;
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
//子弹击中目标
void Bullet::hitTarget(){
    /*if(map->enemy_list.indexOf(E_target)!=-1)
        E_target->getDamage(damage);
    map->removedBullet(this);*/
    target_object->getDamage(damage);

}
bool Bullet::get_state(){
    return hit_state;
}
