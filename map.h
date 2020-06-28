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

//游戏结果页面
class Result : public QWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    void win();     //游戏胜利
    void fail();    //游戏失败
    void set_pix(QPixmap p)     {pix = p;}   //设置结果图像
    void last_map()             {last = true;}       //第三关结束
signals:
    void restart();     //重新开始信号
    void quit();        //退出关卡信号
private slots:
    void on_quit_clicked();     //退出关卡
    void on_restart_clicked();  //重新开始
private:
    Ui::Result *ui;
    QPixmap pix;        //结果图像
    bool last;          //是否为第三关
};

//地图类
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

    void paintEvent(QPaintEvent *event);    //绘制函数

    void set_life_total(int);       //设置生命数
    void set_money_start(int);      //设置初始金币
    void set_wave_total(int);       //设置总波数
    void set_enemy_load(vector<vector<int>>,
                        vector<vector<int>>,
                        vector<vector<int>>,
                        vector<vector<int>>);   //载入敌人

    virtual void addWayPoints();    //设置航点
    virtual void addPlaces();       //设置防御点

    void game_result();     //判定游戏结果

    void removedElf(Elf* elf);          //移去防御塔
    void removedEnemy(Enemy* enemy);    //移去敌人
    void removedBullet(Bullet* bullet); //移去子弹

    void set_map(QPixmap p){map = p;}   //载入地图图片

    void attack(Object *attacker,Object *target);   //攻击锁定
signals:
    void Backsub(Map*);     //返回关卡选择页面
public slots:
    void updateMap();                       //刷新页面

    void build_rock(Place*,QPushButton*);   //建造一类防御塔
    void build_ice(Place*,QPushButton*);    //建造二类防御塔
    void build_grass(Place*,QPushButton*);  //建造三类防御塔

    void loadWave();        //载入一波敌人

    void deal_damage(Enemy*);   //敌人进入基地

    void deal_restart();    //重新开始
    void deal_quit();       //退出关卡
    void sell_elf(Elf *);   //售卖防御塔
    void up_elf(Elf *);     //升级防御塔
    void check_enemy();     //检查敌人是否消灭完
    void delete_ptr(QTimer*);
private slots:
    void on_backsub_clicked();  //返回关卡选择页面
    void on_start_clicked();    //开始关卡
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
    //敌人生成时间列
    vector<vector<int>> enemy1_load;
    vector<vector<int>> enemy2_load;
    vector<vector<int>> enemy3_load;
    vector<vector<int>> enemy4_load;

    QTimer* timer1;
    QTimer* timer2;

    bool game_win;          //游戏结果
    QPixmap map;            //地图图片

    QMediaPlaylist *playlist;   //BGM列表
    QMediaPlayer* player;
    QMediaPlayer* player_bgm;
    Result* res;        //结果页面
    QPixmap pix1;
    QPixmap pix2;

    bool map3;      //是否为第三关
};
//地图一
class Map1 : public Map
{
    Q_OBJECT
public:
    explicit Map1(Map *parent = nullptr);
    ~Map1();
    void addPlaces();       //设置防御点
    void addWayPoints();    //设置航点
};
//地图二
class Map2 : public Map
{
    Q_OBJECT
public:
    explicit Map2(Map *parent = nullptr);
    ~Map2();
    void addPlaces();       //设置防御点
    void addWayPoints();    //设置航点
};
//地图三
class Map3 : public Map
{
    Q_OBJECT
public:
    explicit Map3(Map *parent = nullptr);
    ~Map3();
    void addPlaces();       //设置防御点
    void addWayPoints();    //设置航点
};
#endif // MAP_H
