TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackelement.cpp \
    stack.cpp

HEADERS += \
    stackelement.h \
    stack.h

QMAKE_CXXFLAGS += -std=c++0x
