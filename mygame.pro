#-------------------------------------------------
#
# Project created by QtCreator 2020-05-11T23:20:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mygame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    subwidget.cpp \
    map.cpp \
    mainwidget.cpp \
    place.cpp \
    object.cpp \
    elf.cpp \
    enemy.cpp \
    bullet.cpp

HEADERS += \
    subwidget.h \
    map.h \
    mainwidget.h \
    place.h \
    object.h \
    elf.h \
    enemy.h \
    bullet.h \
    public.h

FORMS += \
    map1.ui \
    place.ui \
    subwidget.ui \
    mainwidget.ui \
    option.ui \
    result.ui \
    result.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    images/place point/cancel.png \
    images/place point/grass.png \
    images/place point/ice.png \
    images/place point/rock.png \
    images/place point/sell.png \
    images/place point/up1.png \
    images/place point/up2.png

