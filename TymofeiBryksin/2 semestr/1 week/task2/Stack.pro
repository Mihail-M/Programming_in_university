
QT       += core

QT       -= gui

QT       += testlib
TARGET = List
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    stack.cpp \
    stackpointer.cpp \
    stackarr.cpp \
    calc.cpp

HEADERS += \
    stack.h \
    stackarr.h \
    stackpointer.h \
    calc.h \
    teststack.h \
    testcalc.h



