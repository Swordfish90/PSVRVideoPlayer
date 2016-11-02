TEMPLATE = app

TARGET = psvrvideoplayer

DESTDIR = $$OUT_PWD/../

QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    qmlpsvr.cpp \
    psvrsensorsmanager.cpp

HEADERS += \
    qmlpsvr.h \
    psvrsensorsmanager.h

RESOURCES += qml.qrc

LIBS += -L$$OUT_PWD/../libpsvr -lpsvr

# TODO These paths are platform dependent.

LIBS += -lusb-1.0

INCLUDEPATH += /usr/include/libusb-1.0
