/********************************************************************************
** Form generated from reading UI file 'map1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP1_H
#define UI_MAP1_H

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

class Ui_Map1
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QSpacerItem *horizontalSpacer;
    QPushButton *backsub;
    QPushButton *b_1;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLabel *money;
    QLabel *times;
    QPushButton *b_2;
    QPushButton *b_3;
    QPushButton *b_4;
    QPushButton *b_5;
    QPushButton *b_6;
    QWidget *widget;

    void setupUi(QWidget *Map1)
    {
        if (Map1->objectName().isEmpty())
            Map1->setObjectName(QStringLiteral("Map1"));
        Map1->resize(1200, 750);
        Map1->setMinimumSize(QSize(1200, 750));
        Map1->setStyleSheet(QLatin1String("\n"
"border-image: url(:/images/images/maps/map1.jpg);\n"
"border-image: url(:/images/images/place point/empt.png);\n"
""));
        layoutWidget = new QWidget(Map1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(841, 671, 288, 53));
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

        b_1 = new QPushButton(Map1);
        b_1->setObjectName(QStringLiteral("b_1"));
        b_1->setGeometry(QRect(480, 170, 93, 51));
        b_1->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        layoutWidget1 = new QWidget(Map1);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 193, 199));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(191, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\347\224\237\345\221\275.png);"));

        verticalLayout->addWidget(pushButton);

        money = new QLabel(layoutWidget1);
        money->setObjectName(QStringLiteral("money"));
        money->setMinimumSize(QSize(191, 61));
        money->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\351\207\221\345\270\201.png);"));

        verticalLayout->addWidget(money);

        times = new QLabel(layoutWidget1);
        times->setObjectName(QStringLiteral("times"));
        times->setMinimumSize(QSize(191, 61));
        times->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\346\263\242\346\254\241.png);"));

        verticalLayout->addWidget(times);

        b_2 = new QPushButton(Map1);
        b_2->setObjectName(QStringLiteral("b_2"));
        b_2->setGeometry(QRect(1100, 270, 93, 51));
        b_2->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        b_3 = new QPushButton(Map1);
        b_3->setObjectName(QStringLiteral("b_3"));
        b_3->setGeometry(QRect(680, 240, 93, 51));
        b_3->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        b_4 = new QPushButton(Map1);
        b_4->setObjectName(QStringLiteral("b_4"));
        b_4->setGeometry(QRect(390, 340, 93, 51));
        b_4->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        b_5 = new QPushButton(Map1);
        b_5->setObjectName(QStringLiteral("b_5"));
        b_5->setGeometry(QRect(600, 480, 93, 51));
        b_5->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        b_6 = new QPushButton(Map1);
        b_6->setObjectName(QStringLiteral("b_6"));
        b_6->setGeometry(QRect(1130, 280, 93, 51));
        b_6->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/place.png);"));
        widget = new QWidget(Map1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(480, 680, 120, 80));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/\347\273\210\347\202\271.png);"));

        retranslateUi(Map1);

        QMetaObject::connectSlotsByName(Map1);
    } // setupUi

    void retranslateUi(QWidget *Map1)
    {
        Map1->setWindowTitle(QApplication::translate("Map1", "Form", nullptr));
        start->setText(QString());
        backsub->setText(QString());
        b_1->setText(QString());
        pushButton->setText(QString());
        money->setText(QString());
        times->setText(QString());
        b_2->setText(QString());
        b_3->setText(QString());
        b_4->setText(QString());
        b_5->setText(QString());
        b_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Map1: public Ui_Map1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP1_H
