#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T12:28:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    textview.cpp \
    dataview.cpp \
    rubrics.cpp \
    newuser.cpp \
    forgotpassword.cpp



HEADERS  += mainwindow.h \
    textview.h \
    dataview.h \
    rubrics.h \
    newuser.h \
    forgotpassword.h


FORMS    += mainwindow.ui \
    textview.ui \
    dataview.ui \
    rubrics.ui \
    newuser.ui \
    forgotpassword.ui

RESOURCES += \
    logo.qrc

DISTFILES += \
    Logo.png \
    Student.java

SOURCES +=  ../project/code.cpp\

HEADERS +=    ../project/code.h\

SOURCES += ../DataStructure/feedback.cpp
HEADERS += ../DataStructure/feedback.h

SOURCES += ../DataStructure/ident.cpp
HEADERS += ../DataStructure/ident.h

SOURCES += ../DataStructure/dbtable.cpp
HEADERS += ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp
HEADERS += ../DataStructure/dbtool.h

LIBS += -l sqlite3

