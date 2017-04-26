QT += core
QT -= gui

TARGET = PrimeNumberSieve
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    primethread.cpp

HEADERS += \
    primethread.h

