#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include "subwidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget//主窗口
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void paintEvent(QPaintEvent *);
    void dealBack();
    //void dealmap1();
private slots:
    void on_Begin_clicked();

private:
    Ui::MainWidget *ui;
    QPushButton Begin;
    QPushButton Exit;
    SubWidget Subw;
};

#endif // WIDGET_H
