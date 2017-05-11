TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    configuration.cpp \
    baseclass.cpp \
    log.cpp

HEADERS += \
    configuration.h \
    baseclass.h \
    log.h
