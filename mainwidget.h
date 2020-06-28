#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QDebug>
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
public slots:
    void dealBack();
    void dealmap1();
private slots:
    void on_Begin_clicked();

    void on_Exit_clicked();

private:
    Ui::MainWidget *ui;
    QPushButton Begin;
    QPushButton Exit;
    SubWidget Subw;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
};

#endif // WIDGET_H
