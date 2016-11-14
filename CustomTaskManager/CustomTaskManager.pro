#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T15:23:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CustomTaskManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    cpuhandler.cpp \
    graphichandler.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    cpuhandler.h \
    graphichandler.h

FORMS    += mainwindow.ui
