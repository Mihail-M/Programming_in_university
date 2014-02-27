TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    list.cpp \
    circulyrlist.cpp \
    acicliclist.cpp

HEADERS += \
    list.h \
    circulyrlist.h \
    acicliclist.h



