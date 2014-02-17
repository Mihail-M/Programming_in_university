TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PhoneBook.cpp

HEADERS += \
    PhoneBook.h

QMAKE_CXXFLAGS += -std=c++0x
