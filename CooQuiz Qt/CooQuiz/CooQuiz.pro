#-------------------------------------------------
#
# Project created by QtCreator 2016-08-30T13:20:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CooQuiz
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    pergunta.cpp \
    quiz.cpp \
    conexaodb.cpp \
    loguin.cpp \
    usuario.cpp

HEADERS  += mainwindow.h \
    pergunta.h \
    quiz.h \
    conexaodb.h \
    loguin.h \
    usuario.h

FORMS    += mainwindow.ui \
    loguin.ui
