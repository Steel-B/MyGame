/********************************************************************************
** Form generated from reading UI file 'place.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACE_H
#define UI_PLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Place
{
public:
    QPushButton *button;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *rock;
    QSpacerItem *horizontalSpacer;
    QPushButton *ice;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *grass;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancel1;

    void setupUi(QWidget *Place)
    {
        if (Place->objectName().isEmpty())
            Place->setObjectName(QStringLiteral("Place"));
        Place->resize(163, 161);
        button = new QPushButton(Place);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(30, 30, 95, 90));
        button->setStyleSheet(QStringLiteral("border-image: url(:/images/images/place point/empt.png);"));
        layoutWidget = new QWidget(Place);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 161, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rock = new QPushButton(layoutWidget);
        rock->setObjectName(QStringLiteral("rock"));
        rock->setMinimumSize(QSize(50, 60));
        rock->setMaximumSize(QSize(93, 101));
        rock->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/rock_.png);"));

        gridLayout->addWidget(rock, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(30, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        ice = new QPushButton(layoutWidget);
        ice->setObjectName(QStringLiteral("ice"));
        ice->setMinimumSize(QSize(61, 61));
        ice->setMaximumSize(QSize(93, 101));
        ice->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/ice_.png);"));

        gridLayout->addWidget(ice, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        grass = new QPushButton(layoutWidget);
        grass->setObjectName(QStringLiteral("grass"));
        grass->setMinimumSize(QSize(61, 61));
        grass->setMaximumSize(QSize(71, 81));
        grass->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/grass_.png);"));

        gridLayout->addWidget(grass, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        cancel1 = new QPushButton(layoutWidget);
        cancel1->setObjectName(QStringLiteral("cancel1"));
        cancel1->setMinimumSize(QSize(61, 56));
        cancel1->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/cancel.png);"));

        gridLayout->addWidget(cancel1, 2, 2, 1, 1);

        layoutWidget->raise();
        button->raise();

        retranslateUi(Place);

        QMetaObject::connectSlotsByName(Place);
    } // setupUi

    void retranslateUi(QWidget *Place)
    {
        Place->setWindowTitle(QApplication::translate("Place", "Form", nullptr));
        button->setText(QString());
        rock->setText(QString());
        ice->setText(QString());
        grass->setText(QString());
        cancel1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Place: public Ui_Place {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACE_H
