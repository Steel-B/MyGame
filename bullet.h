#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QVector2D>
#include <QPainter>
#include <QDebug>
#include "object.h"
#include "public.h"

//子弹类
class Bullet:public QObject
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);

    void draw(QPainter*painter);                                    //绘制子弹
    void move();                                                    //子弹移动函数

    void set_cast_object(Object *o);                                //设置发射对象
    Object* get_cast_object()           {return cast_object;}       //获取发射对象
    void set_target_object(Object *o)   {target_object = o;}        //设置目标对象
    Object* get_target_object()         {return target_object;}     //获取目标对象

    void set_current_pos(QPoint pos)    {current_point = pos;}      //设置当前位置
    QPoint get_current_pos()            {return current_point;}     //获取当前位置
    QPoint get_start_pos()              {return start_point;}       //获取初始位置
    QPoint get_target_pos()             {return target_point;}      //获取目标位置

    void set_pixmap(QPixmap p)          {pixmap = p;}               //载入子弹图像

    void set_ice()                      {ice = true;}               //设置冰属性
    bool get_ice()                      {return ice;}               //获取冰属性
    void set_damage(int d)              {damage = d;}               //设置伤害
    int get_damage()                    {return damage;}            //获取伤害
    void hitTarget();                                               //击中目标
    bool get_state()                    {return hit_state;}         //获取是否击中状态
signals:
    void removedBullet(Bullet*);        //移去子弹信号
private:
    QPoint start_point;         //开始位置
    Object* cast_object;        //发射对象
    Object* target_object;      //目标对象
    QPoint target_point;        //目标位置
    QPoint current_point;       //当前位置
    int damage;                 //子弹伤害
    int speed;                  //子弹移动速度
    QPixmap pixmap;             //子弹图像
    bool hit_state;             //子弹是否击中
    bool ice;                   //子弹是否有冰属性
};

#endif // BULLET_H
