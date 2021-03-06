TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT+= core

LIBS += -l sqlite3 \
        -pthread

SOURCES += main.cpp \
    code.cpp

HEADERS += \
    code.h \
    macros.h

HEADERS += ../DataStructure/dbtool.h \
    ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp \
    ../DataStructure/dbtable.cpp

SOURCES +=
    ../Integration/integration.cpp

HEADERS += \
    ../Integration/integration.h

SOURCES += \
    ../DataStructure/student.cpp \
    ../DataStructure/students.cpp \
    ../DataStructure/assignments.cpp \
    ../DataStructure/assignment.cpp \
    #../DataStructure/rubrics.cpp \
    ../DataStructure/rubric.cpp \
    ../DataStructure/category.cpp \
    ../DataStructure/ident.cpp \
    ../DataStructure/feedback.cpp

HEADERS += \
    ../DataStructure/student.h \
    ../DataStructure/students.h \
    ../DataStructure/assignments.h \
    ../DataStructure/assignment.h \
    #../DataStructure/rubrics.h \
    ../DataStructure/rubric.h \
    ../DataStructure/category.h \
    ../DataStructure/ident.h \
    ../DataStructure/feedback.h

HEADERS += ../git/git.h \
           ../git/bash.h

SOURCES += ../git/git.cpp \
           ../git/bash.cpp

HEADERS += ../tools/baseclass.h \
        ../tools/configuration.h \
        ../tools/log.h

SOURCES += ../tools/baseclass.cpp \
        ../tools/configuration.cpp \
        ../tools/log.cpp

DISTFILES += \
    ../../../Desktop/Wheel.java

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest
