#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T15:23:24
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CustomTaskManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    cpuhandler.cpp \
    memoryhandler.cpp \
    batteryhandler.cpp \
    process.cpp \
    processhandler.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    cpuhandler.h \
    memoryhandler.h \
    batteryhandler.h \
    process.h \
    operationtype.h \
    processhandler.h

FORMS    += mainwindow.ui
