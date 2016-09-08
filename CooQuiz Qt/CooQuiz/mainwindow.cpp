#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loguin.h"
#include <iostream>


quiz* MainWindow::mainquiz = new quiz(1,2);
int MainWindow::questaoAtual = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resposta=4;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainquiz;
}

//seta os textos de perguntas e alternativas;

void MainWindow::on_pushButton_comecar_clicked()
{
    std::string cabecalho = mainquiz->Perguntas[this->questaoAtual].getCabecalho();
    std::string alternativa1 = mainquiz->Perguntas[this->questaoAtual].getAlternativas(0);
    std::string alternativa2 = mainquiz->Perguntas[this->questaoAtual].getAlternativas(1);
    std::string alternativa3 = mainquiz->Perguntas[this->questaoAtual].getAlternativas(2);
    std::string alternativa4 = mainquiz->Perguntas[this->questaoAtual].getAlternativas(3);

    QString a;

    ui->textBrowser_questao->setHtml("<h3>" + a.setNum(questaoAtual+1) + "º QUESTÃO:"  + "</h3>" + a.fromStdString(cabecalho));
    ui->textBrowser_alternativa_a->setHtml("<h5>" + a.fromStdString(alternativa1) + "</h5>");
    ui->textBrowser_alternativa_b->setHtml("<h5>" + a.fromStdString(alternativa2) + "</h5>");
    ui->textBrowser_alternativa_c->setHtml("<h5>" + a.fromStdString(alternativa3) + "</h5>");
    ui->textBrowser_alternativa_d->setHtml("<h5>" + a.fromStdString(alternativa4) + "</h5>");

}

//butoes de resposta

void MainWindow::on_radioButton_a_clicked()
{
    resposta = 0;
}

void MainWindow::on_radioButton_b_clicked()
{
    resposta = 1;
}

void MainWindow::on_radioButton_c_clicked()
{
    resposta = 2;
}

void MainWindow::on_radioButton_d_clicked()
{
    resposta = 3;
}

//envia resposta
void MainWindow::on_pushButton_enviar_clicked()

{
    QMessageBox a;
    if(mainquiz->Perguntas[this->questaoAtual].getResposta(resposta) == true){
        a.about(this, "Correcao" , "correto");
        //mainquiz->pontuacao++;
    }else{
        a.about(this, "Correção" , "incorreto");
    }

    this->questaoAtual ++;

    //para verificar o debug
    std::cout << (int)mainquiz->Perguntas.size()<< std::endl;
    std::cout << questaoAtual << std::endl;

    //verifica se a quantidade de questoes foi preencrida
    if(questaoAtual != (int)mainquiz->Perguntas.size()){
    on_pushButton_comecar_clicked();
    }else{
        close();
    }
}
