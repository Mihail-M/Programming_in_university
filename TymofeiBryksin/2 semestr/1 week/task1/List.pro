#-------------------------------------------------
#
# Project created by QtCreator 2014-03-15T03:11:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib
TARGET = List
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    list.cpp \
    circulyrlist.cpp \
    acicliclist.cpp

HEADERS += \
    list.h \
    circulyrlist.h \
    acicliclist.h \
    testAciclicList.h \
    testCicrculyrList.h



