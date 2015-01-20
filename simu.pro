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
    ../gpp_qt/cmd_line/cmd_line.cpp \
    ../gpp_qt/log_info/log_info.cpp \
    ../gpp_qt/log_info/logs.cpp

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
    ../gpp_qt/cmd_line/cmd_line.h \
    ../gpp_qt/log_info/log_info.h \
    ../gpp_qt/log_info/logs.h

FORMS    += mainwindow.ui
