#include "bullet.h"

Bullet::Bullet(QObject *parent):
    QObject(parent)
{

}
//绘制子弹
void Bullet::draw(QPainter*painter){

}
//子弹移动
void Bullet::move(){
    static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this,"current_point");
    animation->setDuration(duration);
    animation->setStartValue(start_point);
    animation->setEndValue(target_point);
    connect(animation,SIGNAL(finished()),this,SLOT(hitTarget()));
}
//设置子弹当前位置
void Bullet::set_current(QPoint pos){
    current_point = pos;
}
//返回子弹当前位置
QPoint Bullet::current(){
    return current_point;
}
//子弹击中敌人
void Bullet::hitTarget_E(){
    if(map->enemy_list.indexOf(E_target)!=-1)
        E_target->getDamage(damage);
    map->removedBullet(this);
}
