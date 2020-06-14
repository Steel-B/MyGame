#include "mainwidget.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget main;
    main.setWindowTitle(QString("精灵塔防"));
    main.show();
    return a.exec();
}
