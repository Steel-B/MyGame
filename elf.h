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
    void set_elf(Elf*,QPainter*);
signals:
    void sell();
    void up();
public slots:
private slots:
    void on_cancel2_clicked();
    void on_sell_clicked();
    void on_up_clicked();

private:
    Ui::Option *ui;
    Elf* elf;
};
class Elf :public Object
{
    Q_OBJECT
public:
    friend class Rock;
    friend class Ice;
    friend class Grass;
    explicit Elf(Object *parent = nullptr);
    ~Elf();
    void setopt()               {opt = new Option;}
    Option* getopt()            {return opt;}
    void set_cost(int c)        {cost = c;}
    int get_cost()              {return cost;}
    void set_button(QPushButton* b){button = b;}
    QPushButton* get_button()   {return button;}
    virtual void up();

signals:
    void sell_signal(Elf*);
    void up_signal(Elf*);
    void draw_range(Elf*);
public slots:
    void option_show();
    void sell();
    void up_signal_emit();
private:
    QPushButton* button;
    int level;//防御塔等级
    Option* opt;
    QPixmap pixmap;
    QPixmap pixmap1;
    QPixmap pixmap2;
    QPixmap pixmap3;
    int cost;
};
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
