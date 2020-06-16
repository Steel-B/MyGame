#include "enemy.h"
#include "ui_object.h"
#include "public.h"
#include <QDebug>

//航点类
WayPoint::WayPoint(QPoint pos):
    m_pos(pos),
    m_next(NULL)
{
}
//设置下一航点
void WayPoint::setNext(WayPoint *next){
    m_next = next;
}
//获取下一行点
WayPoint* WayPoint::next()const{
    return m_next;
}
//获取当前航点
const QPoint WayPoint::pos()const{
    return m_pos;
}
//重载WayPoint =
void WayPoint::operator =(const WayPoint* w){
    this->m_pos = w->m_pos;
    this->m_next = w->m_next;
}

//敌人类
Enemy::Enemy(Object *parent) : Object(parent)
{
    set_max_blood(60);
    move_speed = 5;
    m_active =false;
    this->resize(80,80);
    pixmap= QPixmap(":/images/images/enemy/兔1.png");
}
Enemy::~Enemy(){

}
void Enemy::setdes(WayPoint *des){
    destination = des;
}
void Enemy::draw(QPainter *painter){
    // 血条的长度
    // 其实就是2个方框,红色方框表示总生命,固定大小不变
    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响
    static const int Health_Bar_Width = 20;
    painter->save();
    painter->drawPixmap(get_current_pos(),pixmap);
    //qDebug()<<"the enemy's current position is"<<get_current_pos()<<endl;
    QPoint healthBarPoint = get_current_pos() + QPoint(15, -height() / 6);
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
void Enemy::march(){
    if(!m_active)return;    //如果敌人不能行动，则返回
    if(collision(this->get_current_pos(),1,this->destination.pos(),1)){
        //敌人抵达一个航点
        if(destination.next()){
            //有下一个航点
            this->set_current_pos(destination.pos());
            destination = destination.next();
        }
        else{//敌人进入基地
            emit damage_base();
            return;
        }
    }
    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = destination.pos();
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值
    // 向量标准化
    double movementSpeed = move_speed;
    QVector2D normalized(targetPoint - get_current_pos());
    normalized.normalize();
    set_current_pos(get_current_pos() + normalized.toPoint() * movementSpeed);
}
QPoint Enemy::currentPos(){
    return get_center_pos();
}
void Enemy::setCurrentPos(QPoint p){
    set_center_pos(p);
}
void Enemy::doActiate(){
    m_active =true;
}
Enemy1::Enemy1(Enemy *parent) : Enemy(parent)
{
    set_max_blood(30);
}
Enemy2::Enemy2(Enemy *parent) : Enemy(parent)
{
    set_max_blood(20);
    set_range(100);
}
