#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T16:22:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simu
TEMPLATE = app


SOURCES += main.cpp\
		mainwindow.cpp \
    match_engine.cpp \
    orderlist.cpp \
    fillpolicy.cpp \
    ../only_qt_ctp/tactic.cpp \
    order.cpp

HEADERS  += mainwindow.h \
    match_engine.h \
    orderlist.h \
    fillpolicy.h \
    ../only_qt_ctp/tactic.h \
    order.h

FORMS    += mainwindow.ui
