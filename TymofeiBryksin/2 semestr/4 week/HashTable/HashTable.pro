
QT       += core

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
CONFIG += testlib
//QT += QtTest
QMAKE_CXXFLAGS += -std=c++11
QT += core

SOURCES += \
    main.cpp\
    hashtable.cpp\
    list.cpp\
    acicliclist.cpp \
    userchoice.cpp \
    primitivehashfunction.cpp \
    hashfunction.cpp \
    powerhashfunction.cpp

HEADERS += \
    hashtable.h\
    list.h\
    acicliclist.h \
    userchoice.h \
    primitivehashfunction.h \
    hashfunction.h \
    powerhashfunction.h\
    testhashtable.h \

