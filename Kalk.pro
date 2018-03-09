######################################################################
# Automatically generated by qmake (3.0) gio feb 8 10:55:44 2018
######################################################################

TEMPLATE = app
TARGET = Kalk
INCLUDEPATH += .
QMAKE_CXXFLAGS += -std=c++11
QT += widgets
# Input
HEADERS += Controller/binary_controller.h \
           Controller/eccezioni.h \
           Controller/hex_controller.h \
           Controller/octal_controller.h \
           Model/arithmetic_types.h \
           Model/binary.h \
           Model/hex.h \
           Model/octal.h \
           View/binary_graphic.h \
           View/choose_type.h \
           View/front_graphic.h \
           View/hex_graphic.h \
           View/octal_graphic.h \
    Model/calcola.h \
    Controller/controller.h
SOURCES += main.cpp \
           Controller/binary_controller.cpp \
           Controller/eccezioni.cpp \
           Controller/hex_controller.cpp \
           Controller/octal_controller.cpp \
           Model/binary.cpp \
           Model/hex.cpp \
           Model/octal.cpp \
           View/binary_graphic.cpp \
           View/choose_type.cpp \
           View/front_graphic.cpp \
           View/hex_graphic.cpp \
           View/octal_graphic.cpp \
    Model/calcola.cpp \
    Controller/controller.cpp

RESOURCES += \
    image/image.qrc
