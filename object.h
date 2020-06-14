#ifndef OBJECT_H
#define OBJECT_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>

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
    void set_now_blood(int n);
    int get_now_blood();
    int get_max_blood();
    void _move();
    void set_range(int rg = 0);
    void drawblood(QPainter* painter);
    void getDamage(int damage);
    QPoint get_center_pos(){return center_pos;}
    void set_center_pos(const QPoint & p){center_pos = p;}
    QPoint get_current_pos(){return current_pos;}
    void set_current_pos(QPoint p){current_pos = p;}
signals:

public slots:
private slots:
    //void on_object_clicked();点击精灵弹出选项，将在elf类中完成

private:
    //Ui::Object *ui_ob;
    int max_blood;
    int current_blood;
    int attack_range;//攻击范围
    QPoint current_pos;//当前位置
    QPoint center_pos; //当前中心点坐标
};

#endif // OBJECT_H
