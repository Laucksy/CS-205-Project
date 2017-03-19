TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp \
    assignments.cpp \
    assignment.cpp \
    rubrics.cpp \
    rubric.cpp \
    category.cpp

HEADERS += \
    student.h \
    assignments.h \
    assignment.h \
    rubrics.h \
    rubric.h \
    category.h
