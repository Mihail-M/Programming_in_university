TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    circulyrList.cpp \
    uncirculyrlist.cpp


HEADERS += \
    circulyrList.h \
    uncirculyrList.h

