TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    stack.cpp \
    stackpointer.cpp \
    stackarr.cpp \
    calc.cpp

HEADERS += \
    stack.h \
    stackarr.h \
    stackpointer.h \
    calc.h



