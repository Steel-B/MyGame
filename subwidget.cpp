#include "subwidget.h"
#include "ui_subw.h"

SubWidget::SubWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Subw)
{
    ui->setupUi(this);
    connect(&back,&QPushButton::clicked,this,&SubWidget::on_back_clicked);
}
SubWidget::~SubWidget(){
    delete ui;
}

void SubWidget::on_back_clicked()
{
    emit Backmenu();
}
