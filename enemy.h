#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QVector2D>
#include <qmath.h>
#include <QPixmap>
#include "object.h"
#include "map.h"

class WayPoint
{
public:
    WayPoint(QPoint pos = *new QPoint);
    void setNext(WayPoint *next);
    WayPoint* next()const;
    const QPoint pos()const;
    void operator=(const WayPoint* w);
private:
    QPoint m_pos;
    WayPoint * m_next;
};

class Enemy : public Object
{
    Q_OBJECT
    //Q_PROPERTY(QPoint currentPos READ currentPos WRITE setCurrentPos NOTIFY currentPosChanged)
public:
    explicit Enemy(Object *parent = nullptr);
    void setdes(WayPoint *des){destination = des;}
    void march();
    void draw(QPainter *painter);
    QPoint currentPos();
    void setCurrentPos(QPoint);
signals:
    void damage_base();
public slots:
    void doActiate();
private:
    double move_speed;  //前进速度
    WayPoint destination;//目标点
    int value;  //死亡奖励数
    QPixmap pixmap;
    bool m_active;
};

class Enemy1 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy1(Enemy *parent = nullptr);

signals:

public slots:
};

class Enemy2 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy2(Enemy *parent = nullptr);

signals:

public slots:
};

#endif // ENEMY_H
