/********************************************************************************
** Form generated from reading UI file 'subw.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBW_H
#define UI_SUBW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subw
{
public:
    QWidget *widget_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout;
    QPushButton *back;
    QPushButton *b1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *b2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *b3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *Subw)
    {
        if (Subw->objectName().isEmpty())
            Subw->setObjectName(QStringLiteral("Subw"));
        Subw->resize(1200, 750);
        Subw->setMinimumSize(QSize(1200, 550));
        widget_4 = new QWidget(Subw);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 180, 1200, 370));
        widget_4->setMinimumSize(QSize(1200, 370));
        widget_4->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/grey.png);"));
        layoutWidget = new QWidget(Subw);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(25, 16, 1151, 711));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(189, 120));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/1.png);"));

        horizontalLayout->addWidget(widget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(189, 120));
        widget_2->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/2.png);"));

        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget_3 = new QWidget(layoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(189, 120));
        widget_3->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/3.png);"));

        horizontalLayout->addWidget(widget_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        back = new QPushButton(layoutWidget);
        back->setObjectName(QStringLiteral("back"));
        back->setMinimumSize(QSize(100, 50));
        back->setMaximumSize(QSize(100, 50));
        back->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/back.png);"));

        gridLayout->addWidget(back, 2, 6, 1, 1);

        b1 = new QPushButton(layoutWidget);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setMinimumSize(QSize(100, 40));
        b1->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/b1.png);"));

        gridLayout->addWidget(b1, 0, 2, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(270, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 2, 1);

        b2 = new QPushButton(layoutWidget);
        b2->setObjectName(QStringLiteral("b2"));
        b2->setMinimumSize(QSize(100, 40));
        b2->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/b2.png);"));

        gridLayout->addWidget(b2, 0, 4, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(270, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 5, 2, 1);

        b3 = new QPushButton(layoutWidget);
        b3->setObjectName(QStringLiteral("b3"));
        b3->setMinimumSize(QSize(100, 40));
        b3->setStyleSheet(QStringLiteral("border-image: url(:/guanqia/b3.png);"));

        gridLayout->addWidget(b3, 0, 6, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 220, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 7, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Subw);
        QObject::connect(back, SIGNAL(clicked()), Subw, SLOT(hide()));
        QObject::connect(b1, SIGNAL(clicked()), Subw, SLOT(hide()));
        QObject::connect(b2, SIGNAL(clicked()), Subw, SLOT(hide()));
        QObject::connect(b3, SIGNAL(clicked()), Subw, SLOT(hide()));

        QMetaObject::connectSlotsByName(Subw);
    } // setupUi

    void retranslateUi(QWidget *Subw)
    {
        Subw->setWindowTitle(QApplication::translate("Subw", "Form", nullptr));
        back->setText(QString());
        b1->setText(QString());
        b2->setText(QString());
        b3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Subw: public Ui_Subw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBW_H
