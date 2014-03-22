#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T19:42:26
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += testlib
TARGET = printer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    filewriter.cpp \
    consolewriter.cpp \
    writer.cpp

HEADERS += \
    filewriter.h \
    consolewriter.h \
    writer.h \
    testprinter.h
