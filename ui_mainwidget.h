/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

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

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *Begin;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Exit;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1200, 750);
        MainWidget->setMinimumSize(QSize(1200, 750));
        MainWidget->setMaximumSize(QSize(1200, 750));
        MainWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(469, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(217, 26, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(469, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(469, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(469, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(217, 368, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        Begin = new QPushButton(MainWidget);
        Begin->setObjectName(QStringLiteral("Begin"));
        Begin->setEnabled(true);
        Begin->setMinimumSize(QSize(220, 100));
        Begin->setStyleSheet(QStringLiteral("border-image: url(:/images/images/menu/Begin.png);"));

        gridLayout->addWidget(Begin, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(217, 97, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        Exit = new QPushButton(MainWidget);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setMinimumSize(QSize(220, 100));
        Exit->setStyleSheet(QStringLiteral("border-image: url(:/images/images/menu/Exit.png);"));

        gridLayout->addWidget(Exit, 3, 1, 1, 1);


        retranslateUi(MainWidget);
        QObject::connect(Begin, SIGNAL(clicked()), Begin, SLOT(hide()));
        QObject::connect(Begin, SIGNAL(clicked()), Exit, SLOT(hide()));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Widget", nullptr));
        Begin->setText(QString());
        Exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
