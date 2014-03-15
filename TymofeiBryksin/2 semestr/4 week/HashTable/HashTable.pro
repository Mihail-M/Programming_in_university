
QT += core

QT -= gui
QT += testlib

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

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

