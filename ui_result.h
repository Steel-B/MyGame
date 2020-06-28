/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Result
{
public:
    QWidget *background;
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *restart;
    QSpacerItem *horizontalSpacer;
    QPushButton *quit;
    QWidget *image;

    void setupUi(QWidget *Result)
    {
        if (Result->objectName().isEmpty())
            Result->setObjectName(QStringLiteral("Result"));
        Result->resize(1200, 750);
        Result->setMinimumSize(QSize(1200, 750));
        background = new QWidget(Result);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-1, 159, 1201, 421));
        background->setStyleSheet(QStringLiteral("border-image: url(:/images/images/levels/grey.png);"));
        widget = new QWidget(background);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(320, 0, 541, 411));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/images/images/maps/win.png);"));
        layoutWidget = new QWidget(Result);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 480, 321, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        restart = new QPushButton(layoutWidget);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setMinimumSize(QSize(100, 40));
        restart->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/restart.png);"));

        horizontalLayout->addWidget(restart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setMinimumSize(QSize(100, 40));
        quit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/maps/quit.png);"));

        horizontalLayout->addWidget(quit);

        image = new QWidget(Result);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(510, 330, 171, 161));
        image->setStyleSheet(QStringLiteral("image: url(:/images/images/maps/res3.png);"));

        retranslateUi(Result);

        QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QWidget *Result)
    {
        Result->setWindowTitle(QApplication::translate("Result", "Form", nullptr));
        restart->setText(QString());
        quit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
