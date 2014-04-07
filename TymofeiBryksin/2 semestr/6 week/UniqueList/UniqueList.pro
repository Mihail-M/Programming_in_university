#-------------------------------------------------
#
# Project created by QtCreator 2014-04-08T00:07:43
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += testlib
TARGET = UniqueList
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app


SOURCES += main.cpp\
        acicliclist.cpp \
        list.cpp \
        uniquelist.cpp \
    exception.cpp

HEADERS += acicliclist.h \
        list.h \
        uniquelist.h \
    exception.h \
    test.h
