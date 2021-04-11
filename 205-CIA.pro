TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += sql

SOURCES += main.cpp \
    pet.cpp \
    tag.cpp \
    helper.cpp

HEADERS += \
    pet.h \
    tag.h \
    helper.h
