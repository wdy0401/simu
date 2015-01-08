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
    order.cpp \
    fillpolicy.cpp \
    match_engine.cpp \
    orderlist.cpp \
    datafeed.cpp \
    orderbook.cpp \
	tactic.cpp \
	snapshot.cpp

HEADERS  += mainwindow.h \
    order.h \
    fillpolicy.h \
    match_engine.h \
    orderlist.h \
    datafeed.h \
    orderbook.h \
	tactic.h \
	snapshot.h \
    parameter.h

FORMS    += mainwindow.ui
