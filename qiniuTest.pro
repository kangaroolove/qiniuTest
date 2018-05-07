#-------------------------------------------------
#
# Project created by QtCreator 2018-05-04T10:01:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qiniuTest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    FileStat.cpp \
    FileCompare.cpp \
    NewDataSync.cpp \
    NewRequest.cpp

HEADERS  += dialog.h \
    FileStat.h \
    FileCompare.h \
    NewDataSync.h \
    NewRequest.h

FORMS    += dialog.ui
