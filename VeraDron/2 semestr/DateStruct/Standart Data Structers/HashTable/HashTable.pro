
QT += core
CONFIG += c++11

CONFIG   += console
CONFIG   -= app_bundle

QT -= gui


TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp\
    hashtable.cpp\
    primitivehashfunction.cpp \
    hashfunction.cpp \
    powerhashfunction.cpp

HEADERS += \
    hashtable.h\
    primitivehashfunction.h \
    hashfunction.h \
    powerhashfunction.h\
    testhashtable.h \

