TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += list.h\
           acicliclist.h
SOURCES += main.cpp\
           list.cpp\
           acicliclist.cpp

QMAKE_CXXFLAGS += -std=c++0x
