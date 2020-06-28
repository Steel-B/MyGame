#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QVector2D>
#include <QPainter>
#include <QDebug>
#include "object.h"
#include "public.h"

class Bullet:public QObject
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);
    void draw(QPainter*painter);
    void move();
    void set_cast_object(Object *o);
    Object* get_cast_object()           {return cast_object;}
    void set_target_object(Object *o)   {target_object = o;}
    Object* get_target_object()         {return target_object;}
    void set_current(QPoint pos)        {current_point = pos;}
    void set_pixmap(QPixmap p)          {pixmap = p;}
    QPoint current_pos()                {return current_point;}
    QPoint start_pos()                  {return start_point;}
    QPoint target_pos()                 {return target_point;}
    void hitTarget();
    bool get_state()                    {return hit_state;}
    void set_ice()                      {ice = true;}
    bool get_ice()                      {return ice;}
    void set_damage(int d)              {damage = d;}
    int get_damage()                    {return damage;}
signals:
    void removedBullet(Bullet*);
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
