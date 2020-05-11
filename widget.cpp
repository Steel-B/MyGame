#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    p1.setParent(this);
    p1.setText("关闭窗口");
    p1.move(150,150);
    connect(&p1,&QPushButton::pressed,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
