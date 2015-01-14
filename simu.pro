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
    fillpolicy.cpp \
    match_engine.cpp \
    datafeed.cpp \
    orderbook.cpp \
	tactic.cpp \
	snapshot.cpp \
	../gpp_qt/wfunction/wfunction.cpp \
    cmd_line.cpp

HEADERS  += mainwindow.h \
    order.h \
    fillpolicy.h \
    match_engine.h \
    datafeed.h \
    orderbook.h \
	tactic.h \
	snapshot.h \
    parameter.h \
	../gpp_qt/wfunction/wfunction.h \
    cmd_line.h

FORMS    += mainwindow.ui
