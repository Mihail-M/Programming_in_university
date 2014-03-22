#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T19:21:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = sorter
CONFIG   += console
CONFIG   -= app_bundle
QT += testlib
TEMPLATE = app


SOURCES += main.cpp \
    bubblesorter.cpp \
    sorter.cpp \
    mergesorter.cpp

HEADERS += \
    sorter.h \
    bubblesorter.h \
    mergesorter.h \
    testsorter.h

