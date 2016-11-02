TEMPLATE = subdirs

QT -= core gui

CONFIG += ordered

SUBDIRS += libpsvr psvrvideoplayerapp

#INCLUDEPATH += $$PWD/libpsvr

#libpsvr.subdir = $$PWD/libpsvr

psvrvideoplayerapp.subdir = $$PWD/psvrvideoplayerapp
psvrvideoplayerapp.depends = libpsvr
