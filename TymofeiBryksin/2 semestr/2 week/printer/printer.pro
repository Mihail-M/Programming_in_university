TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    filewriter.cpp \
    consolewriter.cpp \
    writer.cpp

HEADERS += \
    filewriter.h \
    consolewriter.h \
    writer.h

