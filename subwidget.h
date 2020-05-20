#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "ui_subw.h"


class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    ~SubWidget();
signals:
    void Backmenu();
public slots:

private slots:
    void on_back_clicked();

private:
    Ui::Subw *ui;
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton back;
};

#endif // SUBWIDGET_H
