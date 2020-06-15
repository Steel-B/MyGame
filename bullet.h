#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QVector2D>
#include <QPainter>
#include "object.h"
#include "public.h"

class Bullet:public QObject
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);
    void draw(QPainter*painter);
    void move();
    void set_target_object(Object *o);
    void set_current(QPoint pos);
    QPoint current_pos();
    void hitTarget();
    bool get_state();
    //void hitTarget_T();
private:
    QPoint start_point;//开始位置
    Object* target_object;//目标对象
    QPoint target_point;//目标位置
    QPoint current_point;//当前位置
    int damage;
    int speed;
    QPixmap pixmap;
    bool hit_state;
};

#endif // BULLET_H
