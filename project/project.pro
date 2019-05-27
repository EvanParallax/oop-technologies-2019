#-------------------------------------------------
#
# Project created by QtCreator 2019-04-10T23:31:53
#
#-------------------------------------------------

QT       += core gui svg sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
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

CONFIG += c++17 debug

SOURCES += \
    deletewindow.cpp \
    graphdbhelper.cpp \
        main.cpp \
        window.cpp \
    data/vertex.cpp \
    data/edge.cpp \
    data/graph.cpp \
    data/list.cpp \
    data/node.cpp \
    data/queue.cpp \
    data/stack.cpp \
    data/pair.cpp \
    windowadd.cpp

HEADERS += \
    deletewindow.h \
    graphdbhelper.h \
        window.h \
    data/vertex.h \
    data/edge.h \
    data/graph.h \
    data/list.h \
    data/node.h \
    data/queue.h \
    data/stack.h \
    data/pair.h \
    windowadd.h

FORMS += \
        deletewindow.ui \
        window.ui \
        windowadd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
