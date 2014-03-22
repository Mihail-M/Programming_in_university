#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T20:06:56
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += testlib
TARGET = task3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += sorter.h\
        bubblesorter.h \
    testSorter.h
SOURCES += main.cpp\
        sorter.cpp\
        bubblesorter.cpp
