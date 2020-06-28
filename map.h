#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <vector>
#include "place.h"
#include "elf.h"
#include "enemy.h"
#include "bullet.h"
#include "public.h"
using namespace std;

namespace Ui {
class Map;
class Result;
}

class Result : public QWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    void win();
    void fail();
    void set_pix(QPixmap p){pix = p;}
    //Ui::Result * get_ui(){return ui;}
    void last_map(){last = true;}
signals:
    void restart();
    void quit();
private slots:
    void on_quit_clicked();
    void on_restart_clicked();
private:
    Ui::Result *ui;
    QPixmap pix;
    bool last;
};

class Map : public QWidget
{
    Q_OBJECT
public:
    friend class Map1;
    friend class Map2;
    friend class Map3;
    friend class Bullet;

    explicit Map(QWidget *parent = nullptr);
    ~Map();

    void set_life_total(int);
    void set_money_start(int);
    void set_wave_total(int);
    void set_enemy_load(vector<vector<int>>,vector<vector<int>>,vector<vector<int>>,vector<vector<int>>);

    void addWayPoints();
    void game_result();

    void removedElf(Elf* elf);
    void removedEnemy(Enemy* enemy);
    void removedBullet(Bullet* bullet);

    void paintEvent(QPaintEvent *event);

    void set_map(QPixmap p){map = p;}

    void attack(Object *attacker,Object *target);
signals:
    void Backsub(Map*);
public slots:
    void build_rock(Place*,QPushButton*);
    void build_ice(Place*,QPushButton*);
    void build_grass(Place*,QPushButton*);

    void loadWave();

    void deal_damage(Enemy*);
    void updateMap();

    void deal_restart();
    void deal_quit();
    void sell_elf(Elf *);
    void up_elf(Elf *);
    void check_enemy();
    void delete_ptr(QTimer*);
private slots:
    void on_backsub_clicked();
    void on_start_clicked();
private:
    Ui::Map *ui;
    int life_total;         //初始生命
    int life_current;       //当前生命
    int money_start;        //初始金币数
    int money_current;      //当前金币数
    int wave_total;     //总轮数
    int wave_current;   //目前轮数
    QList<WayPoint*>    waypoint_list;  //航点列
    QList<Elf*>         elf_list;       //防御塔列
    QList<Enemy*>       enemy_list;     //敌人列
    QList<Place*>       place_list;     //防御点列
    QList<Bullet*>      bullet_list;    //子弹列
    QList<Object*>      object_list;    //对象列
    QList<Enemy*>      enemy3_list;    //攻击型敌人列
    vector<vector<int>> enemy1_load;
    vector<vector<int>> enemy2_load;
    vector<vector<int>> enemy3_load;
    vector<vector<int>> enemy4_load;
    QTimer* timer1;
    QTimer* timer2;
    bool game_win;
    QPixmap map;
    QMediaPlaylist *playlist;
    QMediaPlayer* player;
    QMediaPlayer* player_bgm;
    Result* res;
    QPixmap pix1;
    QPixmap pix2;
    bool map3;
};

class Map1 : public Map
{
    Q_OBJECT
public:
    explicit Map1(Map *parent = nullptr);
    ~Map1();
    void addPlaces();
    void addWayPoints();
    //void set_enemy();
};
class Map2 : public Map
{
    Q_OBJECT
public:
    explicit Map2(Map *parent = nullptr);
    ~Map2();
    void addPlaces();
    void addWayPoints();
    //void set_enemy();
};
class Map3 : public Map
{
    Q_OBJECT
public:
    explicit Map3(Map *parent = nullptr);
    ~Map3();
    void addPlaces();
    void addWayPoints();
    //void set_enemy();
};
#endif // MAP_H
