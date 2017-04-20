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
    forgotpassword.cpp \
    rubrictitle.cpp \
    addcategory.cpp \
    newclass.cpp \
    classview.cpp \
    newstudent.cpp \
    newassignment.cpp \
    assignmentview.cpp \
    newsubmission.cpp \
    submissionview.cpp \
    newfile.cpp \
    selectclass.cpp \
    selectrubric.cpp \
    selectassignment.cpp \
    gitmanager.cpp \
    sudentsubdirectory.cpp \
    importclass.cpp \
    importrubric.cpp



HEADERS  += mainwindow.h \
    textview.h \
    dataview.h \
    rubrics.h \
    newuser.h \
    forgotpassword.h \
    rubrictitle.h \
    addcategory.h \
    newclass.h \
    classview.h \
    newstudent.h \
    newassignment.h \
    assignmentview.h \
    newsubmission.h \
    submissionview.h \
    newfile.h \
    selectclass.h \
    selectrubric.h \
    selectassignment.h \
    gitmanager.h \
    sudentsubdirectory.h \
    importclass.h \
    importrubric.h


FORMS    += mainwindow.ui \
    textview.ui \
    dataview.ui \
    rubrics.ui \
    newuser.ui \
    forgotpassword.ui \
    rubrictitle.ui \
    addcategory.ui \
    newclass.ui \
    classview.ui \
    newstudent.ui \
    newassignment.ui \
    assignmentview.ui \
    newsubmission.ui \
    submissionview.ui \
    newfile.ui \
    selectclass.ui \
    selectrubric.ui \
    selectassignment.ui \
    gitmanager.ui \
    sudentsubdirectory.ui \
    importclass.ui \
    importrubric.ui

RESOURCES += \
    logo.qrc

DISTFILES += \
    Logo.png \
    Student.java

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

HEADERS += ../git/bash.h
SOURCES += ../git/bash.cpp

HEADERS += ../export/exporthtml.h
SOURCES += ../export/exporthtml.cpp

HEADERS += ../git/git.h
SOURCES += ../git/git.cpp

HEADERS += ../DataStructure/dbtool.h \
    ../DataStructure/dbtable.h

SOURCES += ../DataStructure/dbtool.cpp \
    ../DataStructure/dbtable.cpp
LIBS += -l sqlite3

