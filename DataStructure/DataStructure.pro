TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -l sqlite3 \
        -pthread

SOURCES += main.cpp \
    student.cpp \
    assignments.cpp \
    assignment.cpp \
    #rubrics.cpp \
    rubric.cpp \
    category.cpp \
    ident.cpp \
    feedback.cpp \
    students.cpp \
    importedrubric.cpp

HEADERS += \
    student.h \
    assignments.h \
    assignment.h \
    #rubrics.h \
    rubric.h \
    category.h \
    ident.h \
    feedback.h \
    students.h \
    importedrubric.h

HEADERS += ../project/code.h

SOURCES += ../project/code.cpp

HEADERS += ../git/git.h \
           ../git/bash.h

SOURCES += ../git/git.cpp \
           ../git/bash.cpp

HEADERS += dbtool.h \
    dbtable.h

SOURCES += dbtool.cpp \
    dbtable.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest
