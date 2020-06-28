/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QSpacerItem *horizontalSpacer;
    QPushButton *backsub;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *life;
    QLabel *money;
    QLabel *wave;

    void setupUi(QWidget *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QStringLiteral("Map"));
        Map->resize(1200, 750);
        Map->setMinimumSize(QSize(1200, 750));
        Map->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"border-image: url(:/images/images/maps/map3.jpg);\n"
"border-image: url(:/images/images/place point/empt.png);\n"
"\n"
"\n"
""));
        layoutWidget = new QWidget(Map);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(841, 690, 288, 53));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start = new QPushButton(layoutWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setMinimumSize(QSize(121, 51));
        start->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\345\274\200\345\247\213.png);"));

        horizontalLayout->addWidget(start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        backsub = new QPushButton(layoutWidget);
        backsub->setObjectName(QStringLiteral("backsub"));
        backsub->setMinimumSize(QSize(111, 51));
        backsub->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\350\277\224\345\233\236.png);"));

        horizontalLayout->addWidget(backsub);

        layoutWidget1 = new QWidget(Map);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 193, 199));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        life = new QLabel(layoutWidget1);
        life->setObjectName(QStringLiteral("life"));
        life->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\347\224\237\345\221\275.png);"));

        verticalLayout->addWidget(life);

        money = new QLabel(layoutWidget1);
        money->setObjectName(QStringLiteral("money"));
        money->setMinimumSize(QSize(191, 61));
        money->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\351\207\221\345\270\201.png);"));

        verticalLayout->addWidget(money);

        wave = new QLabel(layoutWidget1);
        wave->setObjectName(QStringLiteral("wave"));
        wave->setMinimumSize(QSize(191, 61));
        wave->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\346\263\242\346\254\241.png);"));

        verticalLayout->addWidget(wave);


        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QWidget *Map)
    {
        Map->setWindowTitle(QApplication::translate("Map", "Form", nullptr));
        start->setText(QString());
        backsub->setText(QString());
        life->setText(QString());
        money->setText(QString());
        wave->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
