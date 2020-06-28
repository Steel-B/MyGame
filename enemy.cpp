#include "enemy.h"
#include "public.h"
#include <QDebug>

//航点类
WayPoint::WayPoint(QPoint pos):
    m_pos(pos),
    m_next(NULL)
{}

//重载WayPoint =
void WayPoint::operator =(const WayPoint* w){
    this->m_pos = w->m_pos;
    this->m_next = w->m_next;
}

//敌人类
Enemy::Enemy(Object *parent) : Object(parent)
{
    m_active =false;        //初始运动状态
    resize(80,80);          //图片大小
    player = new QMediaPlayer;
    this->setCursor(QCursor(Qt::PointingHandCursor));
    //关联玩家伤害
    connect(this,&Enemy::clicked,this,&Enemy::player_damage);
}
Enemy::~Enemy(){
    delete player;
}

//敌人移动
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
            emit damage_base(this);
            return;
        }
    }
    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = destination.pos();
    // 向量标准化
    double movementSpeed = get_speed();
    QVector2D normalized(targetPoint - get_current_pos());
    normalized.normalize();
    set_current_pos(get_current_pos() + normalized.toPoint() * movementSpeed);
}
//收到玩家伤害
void Enemy::player_damage(){

    player->setMedia(QUrl("qrc:/sound/sound/bullet/hurt.mp3"));
    player->setVolume(30);
    player->play();
    getDamage(300,false);
}
Enemy1::Enemy1(Enemy *parent) : Enemy(parent)
{
    set_max_blood(60);      //血量
    set_speed(3);           //前进速度
    set_value(10);          //死亡金币
    change_attack_ablt();   //不能攻击
    set_pixmap(QPixmap(":/images/images/enemy/rabbit.png"));                //图片
    set_freezed_pix(QPixmap(":/images/images/enemy/rabbit_ice.png"));     //减速图片
    qDebug()<<"structing enemy1";
}
Enemy2::Enemy2(Enemy *parent) : Enemy(parent)
{
    set_max_blood(60);      //血量
    set_speed(3);           //前进速度
    set_value(20);          //死亡金币
    change_attack_ablt();   //不能攻击
    set_pixmap(QPixmap(":/images/images/enemy/bird.png"));                //图片
    set_freezed_pix(QPixmap(":/images/images/enemy/bird_ice.png"));     //减速图片
}
Enemy3::Enemy3(Enemy *parent) : Enemy(parent)
{
    set_max_blood(80);      //血量
    set_speed(3);           //前进速度
    set_value(30);          //死亡金币
    set_range(100);
    set_CD_time(800);
    set_damage(10);
    set_bullet_pix(QPixmap(":/images/images/enemy/bullet/ball.png"));
    set_pixmap(QPixmap(":/images/images/enemy/joker.png"));                //图片
    set_freezed_pix(QPixmap(":/images/images/enemy/joker_ice.png"));     //减速图片
}
Enemy4::Enemy4(Enemy *parent) : Enemy(parent)
{
    set_max_blood(200);      //血量
    set_speed(2);           //前进速度
    set_value(50);          //死亡金币
    set_pixmap(QPixmap(":/images/images/enemy/dragon.png"));                //图片
    set_freezed_pix(QPixmap(":/images/images/enemy/dragon_ice.png"));     //减速图片
}
