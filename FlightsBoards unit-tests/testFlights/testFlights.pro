QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


INCLUDEPATH += ../Flightsboard

SOURCES +=  tst_testflights.cpp \
    ../Flightsboard/flight.cpp

