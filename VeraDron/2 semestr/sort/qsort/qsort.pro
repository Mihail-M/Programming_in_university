TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
HEADERS += test.h
SOURCES += quicksort.cpp
SOURCES += test.cpp

QMAKE_CXXFLAGS += -std=c++0x

