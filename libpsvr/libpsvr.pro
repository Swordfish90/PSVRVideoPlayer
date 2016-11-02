QT -= core gui

TARGET = psvr
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \
	$$PWD/psvr.h \
	$$PWD/morpheus.h

SOURCES += \
        $$PWD/psvr.c

# TODO These paths are device dependent.

INCLUDEPATH += /usr/include/libusb-1.0
