#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T22:50:14
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += serialport
TARGET = commSerial
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tserial.cpp \
    test.cpp

HEADERS += \
    tserial.h \
    test.h
