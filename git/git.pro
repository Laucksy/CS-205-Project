TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    git.cpp \
    bash.cpp

HEADERS += \
    git.h \
    bash.hs
