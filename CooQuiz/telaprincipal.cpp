#include "telaprincipal.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    login_user = new Login;
    login_user->exec();

}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_actionQuiz_Livre_triggered()
{

    opcoes = new OpicoesDoQuiz;
    if(close()){
        opcoes->setLabelTipo("Livre");

        opcoes->exec();
    }
    if(!opcoes->ok){
        show();
        delete opcoes;
    }else{
        telaPerguntas = new telaDePerguntas(this, 1, opcoes->getQtdDeQuestoes());
        telaPerguntas->exec();
        delete opcoes;
    }
    if(!telaPerguntas->ok){
        show();
        delete telaPerguntas;
    }else {
    //adicionar uma função de adicionar a pontuação
    login_user->getUser()->addPontuacao(telaPerguntas->pontuacaoDoQuiz);
    show();
    delete telaPerguntas;
    }

}
