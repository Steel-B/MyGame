#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QVector2D>
#include <qmath.h>
#include <QPixmap>
#include <QMediaPlayer>
#include "object.h"

class WayPoint
{
public:
    WayPoint(QPoint pos = *new QPoint);
    void setNext(WayPoint *next);
    WayPoint* next()const;
    const QPoint pos()const;
    void operator =(const WayPoint* w);
private:
    QPoint m_pos;
    WayPoint * m_next;
};

class Enemy : public Object
{
    Q_OBJECT
public:
    explicit Enemy(Object *parent = nullptr);
    ~Enemy();
    void setdes(WayPoint *des);
    void march();
    QPoint currentPos();
    void setCurrentPos(QPoint);
    void set_value(int v){value = v;}
    int get_value(){return value;}
signals:
    void damage_base(Enemy*);
public slots:
    void doActiate();
    void player_damage();
private:
    WayPoint destination;//目标点
    int value;  //死亡奖励数
    bool m_active;
    QMediaPlayer *player;

};

class Enemy1 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy1(Enemy *parent = nullptr);
};

class Enemy2 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy2(Enemy *parent = nullptr);
};
class Enemy3 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy3(Enemy *parent = nullptr);
};
class Enemy4 : public Enemy
{
    Q_OBJECT
public:
    explicit Enemy4(Enemy *parent = nullptr);
};
#endif // ENEMY_H
