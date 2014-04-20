TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    tree.cpp \
    bstree.cpp

HEADERS += \
    tree.h \
    bstree.h

