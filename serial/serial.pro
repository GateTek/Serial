QT = core
QT += serialport

CONFIG += console
CONFIG -= app_bundle

TARGET = serial
TEMPLATE = app

HEADERS += \
    serial.h

SOURCES += \
    main.cpp \
    serial.cpp
