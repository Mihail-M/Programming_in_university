TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackpointer.cpp \
    stack.cpp

HEADERS += \
    stackpointer.h \
    stack.h

QMAKE_CXXFLAGS += -std=c++0x
