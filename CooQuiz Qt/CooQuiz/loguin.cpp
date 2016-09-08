#include "loguin.h"
#include "ui_loguin.h"
#include "mainwindow.h"

loguin::loguin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loguin)
{
    ui->setupUi(this);
}

loguin::~loguin()
{
    delete ui;
}

//SLOTE QUE CONTEM AS DIRETRIZES DO QUE DEVE ACONTECER AO CLICAR NO BOTÃO ENVIAR
void loguin::on_pushButton_enviar_clicked()
{
    //adquire a string das caixas de texto -lineEdit_login e lineEdit_senha e usa para consultar um usuario no db
    DADOS_DE_USUARIO user = consultarUsuario(ui->lineEdit_login->text().toStdString(), ui->lineEdit_senha->text().toStdString());
    //verifica se o loginName e senha estão corretos
    if (user.loginName == ui->lineEdit_login->text().toStdString() && user.senha == ui->lineEdit_senha->text().toStdString()){
        this->user = new usuario(ui->lineEdit_login->text().toStdString(), ui->lineEdit_senha->text().toStdString());
        //INSTANCIA UM OBJETO QUE MANIPULA A JANELA COM AS QUESTÕES
        static MainWindow w;
        //MOSTRA A JANELA DAS QUESTOES
        w.show();
        //FECHA A JANELA DE LOGIN
        this->close();

    }else{

        QMessageBox a; //ojeto que manipula janelas de mensagens simples
        a.critical(this, "erro", "login ou senha invalida");//envia uma janela com a mensagem de erro
    }
}
