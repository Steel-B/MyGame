#ifndef PLACE_H
#define PLACE_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

namespace Ui {
class Place;
}
//防御点类
class Place : public QWidget
{
    Q_OBJECT
public:
    explicit Place(QWidget *parent = nullptr);
    void build();       //建造选项
    ~Place();
signals:
    //建造防御塔信号
    void build_rock(Place*,QPushButton*);
    void build_ice(Place*,QPushButton*);
    void build_grass(Place*,QPushButton*);
public slots:

private slots:
    void on_cancel1_clicked();  //取消键
    //建造防御塔键
    void on_rock_clicked();
    void on_ice_clicked();
    void on_grass_clicked();

private:
    Ui::Place *ui;
};

#endif // PLACE_H
