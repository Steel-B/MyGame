#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QVector2D>
#include <qmath.h>
#include <QPixmap>
#include <QMediaPlayer>
#include "object.h"

//航点类
class WayPoint
{
public:
    WayPoint(QPoint pos = *new QPoint);
    void setNext(WayPoint *next)            {m_next = next;}     //设置下一航点
    WayPoint* next()const                   {return m_next;}     //获取下一航点
    const QPoint pos()const                 {return m_pos;}      //获取航点坐标
    void operator =(const WayPoint* w);     //重载=
private:
    QPoint m_pos;           //航点坐标
    WayPoint * m_next;      //下一航点
};

//敌人类，继承自对象类
class Enemy : public Object
{
    Q_OBJECT
public:
    explicit Enemy(Object *parent = nullptr);
    ~Enemy();
    void march();       //敌人前进函数
    void set_des(WayPoint *des)   {destination = des;}  //设置目标点
    void set_value(int v)         {value = v;}          //设置死亡奖励
    int get_value()               {return value;}       //获取死亡奖励
signals:
    void damage_base(Enemy*);       //进入基地信号
public slots:
    void change_act_ablt()      {m_active = ! m_active;}//改变运动状态
    void player_damage();       //受到玩家伤害
private:
    WayPoint destination;   //目标点
    int value;              //死亡奖励数
    bool m_active;          //能否运动
    QMediaPlayer *player;

};
//一类敌人
class Enemy1 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy1(Enemy *parent = nullptr);
};
//二类敌人
class Enemy2 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy2(Enemy *parent = nullptr);
};
//三类敌人
class Enemy3 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy3(Enemy *parent = nullptr);
};
//四类敌人
class Enemy4 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy4(Enemy *parent = nullptr);
};
#endif // ENEMY_H
