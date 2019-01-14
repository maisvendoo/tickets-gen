TEMPLATE = app

CONFIG += c++11

TARGET = tickets-gen

DESTDIR = ../bin

QT += core
QT += gui
QT += widgets

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)
