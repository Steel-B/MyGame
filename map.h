#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include "place.h"
#include "enemy.h"
#include "bullet.h"
class Enemy;
class WayPoint;
class Bullet;
namespace Ui {
class Map1;
class Result;
}


class Map : public QWidget
{
    Q_OBJECT
public:
    friend class Map1;
    friend class Bullet;
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    void set_round_total(int);
    void addWayPoints();
    void game_result();
    void deal_damage();
    void removedEnemy(Enemy* enemy);
    void removedBullet(Bullet* bullet);
    bool loadWave(int*);
    void paintEvent(QPaintEvent *event);
    //QPainter* get_painter();
    QList<Enemy*> get_enemy_list();
    void set_map(QPixmap p){map = p;}
signals:

public slots:
    void build_rock(int,int);
    void updateMap();
private:
    int life = 5;       //生命
    int money;      //金币数
    int round_total;//总轮数
    int round_now = 0;  //目前轮数
    QList<WayPoint*> waypoint_list;
    QList<Enemy*> enemy_list;
    QList<Place*> place_list;
    bool game_win;
    QPixmap map;
    //QPainter painter;
};
class Result : public QWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
private:
    Ui::Result *ui;
};

class Map1 : public Map
{
    Q_OBJECT
public:
    explicit Map1(Map *parent = nullptr);
    ~Map1();
    //void paintEvent(QPaintEvent *);
    void addPlaces();
    void addWayPoints();
    void updateMap1();
private slots:

    void on_backsub_clicked();

    void on_b_1_clicked();

    void on_start_clicked();

signals:
    void Backsub();
private:
    Ui::Map1 *ui;
};
#endif // MAP_H
