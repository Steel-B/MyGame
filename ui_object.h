/********************************************************************************
** Form generated from reading UI file 'object.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECT_H
#define UI_OBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Object
{
public:
    QPushButton *object;

    void setupUi(QWidget *Object)
    {
        if (Object->objectName().isEmpty())
            Object->setObjectName(QStringLiteral("Object"));
        Object->resize(262, 182);
        object = new QPushButton(Object);
        object->setObjectName(QStringLiteral("object"));
        object->setGeometry(QRect(80, 80, 81, 111));
        object->setMinimumSize(QSize(81, 81));
        object->setStyleSheet(QStringLiteral("border-image: url(:/images/images/elf/rock3.png);"));

        retranslateUi(Object);

        QMetaObject::connectSlotsByName(Object);
    } // setupUi

    void retranslateUi(QWidget *Object)
    {
        Object->setWindowTitle(QApplication::translate("Object", "Form", nullptr));
        object->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Object: public Ui_Object {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECT_H
