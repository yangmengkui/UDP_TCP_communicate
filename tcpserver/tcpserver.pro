######################################################################
# Automatically generated by qmake (2.01a) fr 16. mar 19:54:14 2007
######################################################################
#QT += qml quick
#QT       += core gui
#CONFIG += c++11

TEMPLATE = app
TARGET = tcpserver
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += \
    ServerStream.h
SOURCES += \
    ServerMain.cpp \
    ServerStream.cpp
QT += network widgets gui core qml quick
CONFIG += console 

RESOURCES += \
    picture.qrc

DISTFILES += \
    main.qml
