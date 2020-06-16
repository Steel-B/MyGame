#ifndef PLACE_H
#define PLACE_H

#include <QWidget>

namespace Ui {
class Place;
}

class Place : public QWidget
{
    Q_OBJECT
public:
    explicit Place(QWidget *parent = nullptr);
    void build();
    ~Place();
signals:
    void build_rock(int x,int y);
    void build_ice(int x,int y);
    void build_grass(int x,int y);
public slots:

private slots:
    void on_cancel1_clicked();
    void on_rock_clicked();
    void on_ice_clicked();
    void on_grass_clicked();

private:
    Ui::Place *ui;
};

#endif // PLACE_H
