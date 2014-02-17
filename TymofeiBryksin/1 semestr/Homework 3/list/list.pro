TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    List.cpp

HEADERS += \
    list.h

QMAKE_CXXFLAGS += -std=c++0x
