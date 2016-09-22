#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QApplication>
#include "usuario.h"
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    usuario *getUser();

private slots:
    void on_pushButton_cancelar_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::Login *ui;
    usuario *user;
};

#endif // LOGIN_H
