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
    Object* get_cast_object();
    void set_target_object(Object *o);
    void set_current(QPoint pos);
    void set_pixmap(QPixmap);
    QPoint current_pos();
    QPoint start_pos();
    QPoint target_pos();
    void hitTarget();
    bool get_state();
    void set_speed_damage(int);
    void set_ice();
    bool get_ice();
    void set_damage(int);
private:
    QPoint start_point;//开始位置
    Object* cast_object;//发射对象
    Object* target_object;//目标对象
    QPoint target_point;//目标位置
    QPoint current_point;//当前位置
    int damage;
    int speed_damage;
    int speed;
    QPixmap pixmap;
    bool hit_state;
    bool ice;
};

#endif // BULLET_H
