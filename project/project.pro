TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    code.cpp

HEADERS += \
    code.h

SOURCES += ../DataStructure/feedback.cpp
HEADERS += ../DataStructure/feedback.h

SOURCES += ../DataStructure/ident.cpp
HEADERS += ../DataStructure/ident.h

DISTFILES += \
    ../../../Desktop/Wheel.java
