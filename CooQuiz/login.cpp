#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
    delete user;
}

usuario *Login::getUser()
{
    return user;
}

void Login::on_pushButton_cancelar_clicked()
{
    exit(0);
}

void Login::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_login->text().toStdString()==
            consultarUsuario(ui->lineEdit_login->text().toStdString(),ui->lineEdit_senha->text().toStdString()).loginName &&
                ui->lineEdit_senha->text().toStdString() == consultarUsuario(ui->lineEdit_login->text().toStdString(),ui->lineEdit_senha->text().toStdString()).senha &&
                    ui->lineEdit_login->text().toStdString() != "" && ui->lineEdit_senha->text().toStdString() != "")
    {
        user = new usuario(ui->lineEdit_login->text().toStdString(),ui->lineEdit_senha->text().toStdString());
        accept();
    }else {
        QMessageBox::critical(this,"erro","login ou senha invalida",QMessageBox::Ok);
    }
}
