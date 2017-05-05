TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

LIBS += -l sqlite3

SOURCES += main.cpp \
    git.cpp \
    bash.cpp

HEADERS += \
    git.h \
    bash.h

SOURCES += \
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

HEADERS += ../project/code.h

SOURCES += ../project/code.cpp

HEADERS += ../DataStructure/dbtool.h \
    ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp \
    ../DataStructure/dbtable.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest
