TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS +=-lwinmm

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

