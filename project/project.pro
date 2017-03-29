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

SOURCES += ../DataStructure/dbtable.cpp
HEADERS += ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp
HEADERS += ../DataStructure/dbtool.h

LIBS += -l sqlite3

DISTFILES += \
    ../../../Desktop/Wheel.java