#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget//主窗口
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
protected:
    void paintEvent(QPaintEvent *);//绘背景图


private slots:
    void on_Begin_clicked();

    void on_Exit_clicked();

private:
    Ui::MainWidget *ui;
    //QPushButton p1;//退出按钮
    QPushButton Begin;
    QPushButton Exit;
};

#endif // WIDGET_H
