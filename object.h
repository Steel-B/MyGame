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

//对象类
class Object : public QPushButton
{
    Q_OBJECT
public:
    friend class Enemy;
    explicit Object(QPushButton *parent = nullptr);
    ~Object();

    void    set_max_blood(int max);     //设置满血量
    int     get_max_blood()             {return max_blood;}         //返回满血量
    void    set_current_blood(int n)    {current_blood = n;}        //设置当前血量
    int     get_current_blood()         {return current_blood;}     //返回当前血量

    void    set_range(int r)            {attack_range = r;}         //设置攻击范围
    int     get_range()                 {return attack_range;}      //返回攻击范围

    void getDamage(int,bool);           //子弹造成伤害

    void    set_current_pos(QPoint p)   {current_pos = p;}      //设置当前位置
    QPoint  get_current_pos()           {return current_pos;}   //返回当前位置

    bool    get_attack_ablt()           {return attack_ablt;}   //返回攻击状态
    void    cooldown();                 //攻击冷却
    void    set_CD_time(int t)          {CD_time = t;}          //设置冷却时间
    int     get_CD_time()               {return CD_time;}       //返回冷却时间

    void    set_pixmap(QPixmap p)       {pixmap = p;}           //载入对象图片
    void    set_freezed_pix(QPixmap p)  {freezed_pix = p;}      //载入冷冻图片
    void    set_bullet_pix(QPixmap p)   {bullet_pix = p;}       //载入子弹图片
    QPixmap get_bullet_pix()            {return bullet_pix;}    //获取子弹图片

    void    draw(QPainter*,bool);       //绘制函数
    void    set_speed(double );         //设置运动速度
    double  get_speed()                 {return move_speed;}    //返回运动速度
    void    freezed();                  //被冷冻
    void    set_ice()                   {ice = true;}       //设置冰属性
    bool    get_ice()                   {return ice;}       //获取冰属性
    void    set_damage(int d)           {damage = d;}       //设置伤害
    int     get_damage()                {return damage;}    //获取伤害
signals:
    void timer_ptr(QTimer*);
public slots:
    void change_attack_ablt()           {attack_ablt = !attack_ablt;}   //更改攻击状态
    void change_state();                //更改冰冻状态
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
};

#endif // OBJECT_H
