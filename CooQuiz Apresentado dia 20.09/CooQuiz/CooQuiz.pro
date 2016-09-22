#-------------------------------------------------
#
# Project created by QtCreator 2016-09-11T13:23:24
#
#-------------------------------------------------


QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CooQuiz
TEMPLATE = app


SOURCES += main.cpp\
        telaprincipal.cpp \
    conexaodb.cpp \
    pergunta.cpp \
    quiz.cpp \
    usuario.cpp \
    login.cpp \
    teladeperguntas.cpp \
    opicoesdoquiz.cpp \
    teladorank.cpp

HEADERS  += telaprincipal.h \
    conexaodb.h \
    pergunta.h \
    quiz.h \
    usuario.h \
    login.h \
    teladeperguntas.h \
    opicoesdoquiz.h \
    teladorank.h

FORMS    += telaprincipal.ui \
    login.ui \
    teladeperguntas.ui \
    opicoesdoquiz.ui \
    teladorank.ui

RESOURCES += \
    imagens.qrc
