TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -l sqlite3

SOURCES += main.cpp \
    exporthtml.cpp

HEADERS += \
    exporthtml.h

HEADERS += ../project/code.h
SOURCES += ../project/code.cpp

SOURCES += ../DataStructure/feedback.cpp
HEADERS += ../DataStructure/feedback.h

SOURCES += ../DataStructure/ident.cpp
HEADERS += ../DataStructure/ident.h

SOURCES += ../DataStructure/dbtable.cpp
HEADERS += ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp
HEADERS += ../DataStructure/dbtool.h

SOURCES += ../DataStructure/assignment.cpp
HEADERS += ../DataStructure/assignment.h

SOURCES += ../DataStructure/assignments.cpp
HEADERS += ../DataStructure/assignments.h

SOURCES += ../DataStructure/rubric.cpp
HEADERS += ../DataStructure/rubric.h

SOURCES += ../DataStructure/student.cpp
HEADERS += ../DataStructure/student.h

SOURCES += ../DataStructure/category.cpp
HEADERS += ../DataStructure/category.h

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
