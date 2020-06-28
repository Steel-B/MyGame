/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

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

class Ui_Option
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *up;
    QSpacerItem *verticalSpacer;
    QPushButton *sell;
    QPushButton *cancel2;

    void setupUi(QWidget *Option)
    {
        if (Option->objectName().isEmpty())
            Option->setObjectName(QStringLiteral("Option"));
        Option->resize(211, 158);
        widget = new QWidget(Option);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 2, 211, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        up = new QPushButton(widget);
        up->setObjectName(QStringLiteral("up"));
        up->setMinimumSize(QSize(61, 56));
        up->setMaximumSize(QSize(71, 71));
        up->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/up1.png);\n"
"border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/up2.png);"));

        gridLayout->addWidget(up, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        sell = new QPushButton(widget);
        sell->setObjectName(QStringLiteral("sell"));
        sell->setMinimumSize(QSize(61, 56));
        sell->setMaximumSize(QSize(71, 71));
        sell->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/sell.png);"));

        gridLayout->addWidget(sell, 2, 0, 1, 1);

        cancel2 = new QPushButton(widget);
        cancel2->setObjectName(QStringLiteral("cancel2"));
        cancel2->setMinimumSize(QSize(61, 56));
        cancel2->setMaximumSize(QSize(71, 71));
        cancel2->setStyleSheet(QLatin1String("border-image: url(:/images/images/place point/empt.png);\n"
"image: url(:/images/images/place point/cancel.png);"));

        gridLayout->addWidget(cancel2, 2, 2, 1, 1);


        retranslateUi(Option);

        QMetaObject::connectSlotsByName(Option);
    } // setupUi

    void retranslateUi(QWidget *Option)
    {
        Option->setWindowTitle(QApplication::translate("Option", "Form", nullptr));
        up->setText(QString());
        sell->setText(QString());
        cancel2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Option: public Ui_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
