TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stack.cpp \
    stackArr.cpp

HEADERS += \
    stack.h \
    stackarr.h

QMAKE_CXXFLAGS += -std=c++0x
