#include "Mainwidget.h"
#include "ui_Mainwidget.h"
#include <QPainter>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    resize(1200,750);
    connect(&Subw,&SubWidget::Backmenu,this,&MainWidget::dealBack);
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
    Subw.setParent(this);
    Subw.show();
}
void MainWidget::dealBack(){
    ui->Begin->show();
    ui->Exit->show();
}
