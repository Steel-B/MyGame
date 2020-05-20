#include "Mainwidget.h"
#include "ui_Mainwidget.h"
#include <QPainter>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    resize(1200,750);

/*
    p1.move(width()/2,height()/2);
    p1.resize(width()/10,height()/10);
    connect(&p1,&QPushButton::pressed,this,&MainWidget::close);
    */
}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/Images/Menu.jpg"));
}
void MainWidget::on_Begin_clicked()
{
    ui->setupUi(this);
    connect(&Begin,&QPushButton::pressed,this,&MainWidget::close);
}

void MainWidget::on_Exit_clicked()
{
    connect(&Exit,&QPushButton::pressed,this,&MainWidget::close);
}
