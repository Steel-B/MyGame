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
    explicit Object(QPushButton *parent = nullptr);
    ~Object();
    void    set_max_blood(int max);
    void    set_current_blood(int n);
    int     get_current_blood();
    int     get_max_blood();
    void    _move();
    void    set_range(int);
    int     get_range();
    void    getDamage(int,bool);
    QPoint  get_center_pos(){return center_pos;}
    void    set_center_pos(const QPoint & p){center_pos = p;}
    QPoint  get_current_pos(){return current_pos;}
    void    set_current_pos(QPoint p){current_pos = p;}
    bool    get_attack_ablt();
    void    cooldown();
    void    set_CD_time(int);
    void    set_pixmap(QPixmap);
    void    set_freezed_pix(QPixmap);
    void    set_bullet_pix(QPixmap);
    QPixmap get_bullet_pix();
    void    draw(QPainter*);
    void    set_speed(double );
    double  get_speed();
    void    freezed();
    void    set_ice();
    bool    get_ice();
    void    set_damage(int);
    int     get_damage();
signals:
public slots:
    void change_attack_ablt();
    void change_state();
private slots:
private:
    double move_speed;  //前进速度
    double low_move_speed;//减速速度
    int max_blood;//满血
    int current_blood;//当前血量
    bool attack_ablt;//能否攻击
    int damage;     //造成伤害
    int attack_range;//攻击范围
    int CD_time;    //攻击冷却时间
    bool ice;//是否有冰属性
    bool freeze;//是否被冰冻
    QPoint current_pos;//当前位置
    QPoint center_pos; //当前中心点坐标
    QPixmap pixmap;//对象图片
    QPixmap freezed_pix;//减速图片
    QPixmap bullet_pix;//子弹图片
};

#endif // OBJECT_H
