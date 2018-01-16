#-------------------------------------------------
#
# Project created by QtCreator 2018-01-11T11:17:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aspick
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    slidermodelclass.cpp \
    sliderviewclass.cpp \
    controlleurclass.cpp \
    baseviewclass.cpp \
    knobviewclass.cpp \
    basemodelclass.cpp \
    knobmodelclass.cpp \
    osc/ip/win32/NetworkingUtils.cpp \
    osc/ip/win32/UdpSocket.cpp \
    osc/ip/IpEndpointName.cpp \
    osc/osc/OscOutboundPacketStream.cpp \
    osc/osc/OscPrintReceivedElements.cpp \
    osc/osc/OscReceivedElements.cpp \
    osc/osc/OscTypes.cpp \
    oscclass.cpp \
    oscpackclass.cpp \
    buttonviewclass.cpp \
    buttonmodelclass.cpp
HEADERS  += mainwindow.h \
    slidermodelclass.h \
    fabriqueclass.h \
    sliderviewclass.h \
    controlleurclass.h \
    baseviewclass.h \
    knobviewclass.h \
    basemodelclass.h \
    knobmodelclass.h \
    osc/ip/IpEndpointName.h \
    osc/ip/NetworkingUtils.h \
    osc/ip/PacketListener.h \
    osc/ip/TimerListener.h \
    osc/ip/UdpSocket.h \
    osc/osc/MessageMappingOscPacketListener.h \
    osc/osc/OscException.h \
    osc/osc/OscHostEndianness.h \
    osc/osc/OscOutboundPacketStream.h \
    osc/osc/OscPacketListener.h \
    osc/osc/OscPrintReceivedElements.h \
    osc/osc/OscReceivedElements.h \
    osc/osc/OscTypes.h \
    oscclass.h \
    oscpackclass.h \
    buttonviewclass.h \
    buttonmodelclass.h

LIBS += -lws2_32
LIBS += -lwinmm

FORMS    += mainwindow.ui

CONFIG += c++11

