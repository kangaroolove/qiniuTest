#-------------------------------------------------
#
# Project created by QtCreator 2018-05-04T10:01:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qiniuTest
TEMPLATE = app
LIBS += -L. -lqiniu -lcurllib -llibeay32 -lssleay32 -lopenldap

SOURCES += main.cpp\
        dialog.cpp \
    FileStat.cpp \
    FileCompare.cpp \
    NewDataSync.cpp \
    NewRequest.cpp \
    Json.cpp \
    https.cpp \
    NewUploadThread.cpp \
    NewDownloadThread.cpp \
    DownloadTask.cpp

HEADERS  += dialog.h \
    FileStat.h \
    FileCompare.h \
    NewDataSync.h \
    NewRequest.h \
    Json.h \
    https.h \
    NewUploadThread.h \
    NewDownloadThread.h \
    DownloadTask.h

FORMS    += dialog.ui
