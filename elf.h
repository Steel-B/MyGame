#ifndef ELF_H
#define ELF_H

#include <QWidget>
#include "place.h"
#include "object.h"
#include "bullet.h"

namespace Ui {
class Option;
}

class Elf;

class Option : public QWidget
{
    Q_OBJECT
public:
    explicit Option(QWidget *parent = nullptr);
    ~Option();
signals:
    void sell();    //售卖防御塔信号
    void up();      //升级防御塔信号
public slots:
private slots:
    void on_cancel2_clicked()   {delete this;}      //选项取消键
    void on_sell_clicked()      {emit sell();}      //售卖键
    void on_up_clicked()        {emit up();}        //升级键

private:
    Ui::Option *ui;
};
class Elf :public Object
{
    Q_OBJECT
public:
    //具体防御塔类
    friend class Rock;
    friend class Ice;
    friend class Grass;
    explicit Elf(Object *parent = nullptr);
    ~Elf();
    void setopt()               {opt = new Option;}//创建选项
    Option* getopt()            {return opt;}      //获取选项指针

    void set_cost(int c)        {cost = c;}         //设置建造花费
    int get_cost()              {return cost;}      //获取建造花费

    void set_button(QPushButton* b){button = b;}    //设置防御点按钮
    QPushButton* get_button()   {return button;}    //获取防御点按钮
    virtual void up();                              //升级虚函数

signals:
    void sell_signal(Elf*);     //售卖信号
    void up_signal(Elf*);       //升级信号
public slots:
    void option_show();     //显示选项界面
    void sell();            //出售防御塔
    void up_signal_emit();  //向地图类发送升级请求
private:
    QPushButton* button;    //防御点按钮
    int level;              //防御塔等级
    Option* opt;            //选项（供升级、出售操作）

    QPixmap pixmap;         //当前图像
    QPixmap pixmap1;        //一级图像
    QPixmap pixmap2;        //二级图像
    QPixmap pixmap3;        //三级图像
    int cost;
};
//一类防御塔
class Rock:public Elf
{
    Q_OBJECT
public:
    explicit Rock(Elf *parent = nullptr);
    ~Rock();
    void up();
signals:

public slots:
private:
};
//二类防御塔
class Ice:public Elf
{
    Q_OBJECT
public:
    explicit Ice(Elf *parent = nullptr);
    ~Ice();
    void up();
signals:

public slots:
private:
};
//三类防御塔
class Grass:public Elf
{
    Q_OBJECT
public:
    explicit Grass(Elf *parent = nullptr);
    ~Grass();
    void up();
signals:

public slots:
private:
};
#endif // ELF_H
