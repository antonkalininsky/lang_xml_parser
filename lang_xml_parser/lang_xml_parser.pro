QT += core
QT += xml
QT -= gui

TARGET = lang_xml_parser
CONFIG += console
CONFIG += C++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    regexcreator.cpp \
    xml_parser.cpp

HEADERS += \
    regexcreator.h \
    xml_parser.h \
    xmladdress.h

