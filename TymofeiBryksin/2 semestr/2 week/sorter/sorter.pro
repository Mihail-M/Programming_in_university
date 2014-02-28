TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubblesorter.cpp \
    sorter.cpp \
    quicksorter.cpp \
    mergesorter.cpp

HEADERS += \
    sorter.h \
    bubblesorter.h \
    quicksorter.h \
    mergesorter.h

