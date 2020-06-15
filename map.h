#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include "place.h"
#include "elf.h"
#include "enemy.h"
#include "bullet.h"
#include "public.h"

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
    //QList<Enemy*> get_enemy_list();
    void set_map(QPixmap p){map = p;}
    void attack(Object *attacker,Object *target);
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
    QList<Elf*> elf_list;
    QList<Enemy*> enemy_list;
    QList<Place*> place_list;
    QList<Bullet*> bullet_list;
    bool game_win;
    QPixmap map;
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
    void addPlaces();
    void addWayPoints();
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
