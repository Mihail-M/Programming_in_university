#-------------------------------------------------
#
# Project created by QtCreator 2014-03-23T16:18:46
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += testlib

QMAKE_CXXFLAGS += -std=c++0x

TARGET = MathTree
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    numbernode.cpp \
    signnode.cpp \
    treenode.cpp \
    treeparse.cpp

HEADERS += \
    treenode.h \
    numbernode.h \
    signnode.h \
    treeparse.h \
    testtreeparse.h
