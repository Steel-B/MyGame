#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QPropertyAnimation>
#include "enemy.h"
#include "map.h"
class Map;
class Enemy;
class Bullet:public QObject
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);
    void draw(QPainter*painter);
    void move();
    void set_current(QPoint pos);
    QPoint current();
    void hitTarget_E();
    //void hitTarget_T();
private:
    Map *map;
    QPoint start_point;
    QPoint target_point;
    QPoint current_point;
    Enemy* E_target;
    int damage;
};

#endif // BULLET_H
