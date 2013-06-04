#-------------------------------------------------
#
# Project created by QtCreator 2013-04-25T03:19:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Maya_meditec
TEMPLATE = app


SOURCES += main.cpp\
        inicio.cpp \
    frmproductosherbolario.cpp \
    configuracion.cpp \
    producto_herbolario.cpp \
    frmfechabaja.cpp \
    frm_plantas_medicinales.cpp \
    plantas.cpp

HEADERS  += inicio.h \
    frmproductosherbolario.h \
    configuracion.h \
    producto_herbolario.h \
    global_includes.h \
    frmfechabaja.h \
    frm_plantas_medicinales.h \
    plantas.h

FORMS    += inicio.ui \
    frmproductosherbolario.ui \
    frmfechabaja.ui \
    frm_plantas_medicinales.ui

RESOURCES += \
    Maya_Meditec.qrc
