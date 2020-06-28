#ifndef OBJECT_H
#define OBJECT_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Object;
}

class Object : public QPushButton
{
    Q_OBJECT
public:
    //friend class Elf;
    //friend class Rock;
    //friend class Ice;
    //friend class Grass;
    friend class Enemy;
    explicit Object(QPushButton *parent = nullptr);
    ~Object();

    void    set_max_blood(int max);
    void    set_current_blood(int n)    {current_blood = n;}
    int     get_current_blood()         {return current_blood;}
    int     get_max_blood()             {return max_blood;}

    void    set_range(int r)            {attack_range = r;}
    int     get_range()                 {return attack_range;}

    void getDamage(int,bool);

    QPoint  get_current_pos()           {return current_pos;}
    void    set_current_pos(QPoint p)   {current_pos = p;}
    bool    get_attack_ablt()           {return attack_ablt;}
    void    cooldown();
    void    set_CD_time(int t)          {CD_time = t;}
    int     get_CD_time()               {return CD_time;}
    void    set_pixmap(QPixmap p)       {pixmap = p;}
    void    set_freezed_pix(QPixmap p)  {freezed_pix = p;}
    void    set_bullet_pix(QPixmap p)   {bullet_pix = p;}
    QPixmap get_bullet_pix()            {return bullet_pix;}
    void    draw(QPainter*,bool);
    void    set_speed(double );
    double  get_speed()                 {return move_speed;}
    void    freezed();
    void    set_ice()                   {ice = true;}
    bool    get_ice()                   {return ice;}
    void    set_damage(int d)           {damage = d;}
    int     get_damage()                {return damage;}
signals:
    void timer_ptr(QTimer*);
public slots:
    void change_attack_ablt()           {attack_ablt = !attack_ablt;}
    void change_state();
private slots:
private:
    double move_speed;      //前进速度
    double low_move_speed;  //减速速度

    int max_blood;          //满血
    int current_blood;      //当前血量

    bool attack_ablt;       //能否攻击
    int damage;             //造成伤害
    int attack_range;       //攻击范围
    int CD_time;        //攻击冷却时间
    bool ice;           //是否有冰属性

    bool freeze;        //是否被冰冻
    QPoint current_pos; //当前位置

    QPixmap pixmap;     //对象图片
    QPixmap freezed_pix;//减速图片
    QPixmap bullet_pix; //子弹图片

    QTimer* timer3;
    //QTimer* timer4;
};

#endif // OBJECT_H
