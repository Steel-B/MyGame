#ifndef ELF_H
#define ELF_H

#include <QWidget>
#include "object.h"
#include "bullet.h"

namespace Ui {
class Option;
}

class Option : public QWidget
{
    Q_OBJECT
public:
    explicit Option(QWidget *parent = nullptr);
    ~Option();
signals:

public slots:
private slots:

private:
    Ui::Option *ui;
};
class Elf :public Object
{
    Q_OBJECT
public:
    explicit Elf(Object *parent = nullptr);
    ~Elf();
    Option* getopt(){return &opt;}
signals:

public slots:
private:
    int level;//防御塔等级
    Option opt;
};
class Rock:public Elf
{
    Q_OBJECT
public:
    explicit Rock(Elf *parent = nullptr);
    paintEvent();
    ~Rock();
signals:

public slots:
private:
};

#endif // ELF_H
