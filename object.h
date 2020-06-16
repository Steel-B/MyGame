#ifndef OBJECT_H
#define OBJECT_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class Object;
}

class Object : public QPushButton
{
    Q_OBJECT
public:
    explicit Object(QPushButton *parent = nullptr);
    ~Object();
    void set_max_blood(int max);
    void set_current_blood(int n);
    int get_current_blood();
    int get_max_blood();
    void _move();
    void set_range(int);
    int get_range();
    void drawblood(QPainter* painter);
    void getDamage(int damage);
    QPoint get_center_pos(){return center_pos;}
    void set_center_pos(const QPoint & p){center_pos = p;}
    QPoint get_current_pos(){return current_pos;}
    void set_current_pos(QPoint p){current_pos = p;}
    bool get_attack_ablt();
    void cooldown();
    void set_CD_time(int);
    void set_bullet_pix(QPixmap);
    QPixmap get_bullet_pix();
signals:
public slots:
    void change_attack_ablt();
private slots:
private:
    int max_blood;
    int current_blood;
    int attack_range;//攻击范围
    int CD_time;    //攻击冷却时间
    bool attack_ablt;//能否攻击
    QPoint current_pos;//当前位置
    QPoint center_pos; //当前中心点坐标
    QPixmap pixmap;//对象图片
    QPixmap bullet_pix;//子弹图片
};

#endif // OBJECT_H
