#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "quiz.h"
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static quiz *mainquiz;
    static int questaoAtual;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_comecar_clicked();

    void on_radioButton_a_clicked();

    void on_radioButton_b_clicked();

    void on_radioButton_c_clicked();

    void on_radioButton_d_clicked();

    void on_pushButton_enviar_clicked();

private:
    int resposta;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
