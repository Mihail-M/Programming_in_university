TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    listelement.cpp \
    circulyr_list.cpp

HEADERS += \
    list.h \
    listelement.h

