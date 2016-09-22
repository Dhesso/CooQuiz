#include "telaprincipal.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    login_user = new Login;
    opcoes = new OpicoesDoQuiz;
    login_user->exec();

}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_actionQuiz_Livre_triggered()
{
    if(close()){
        opcoes->setLabelTipo("Livre");

        opcoes->exec();
    }
    if(!opcoes->ok){
        show();
    }else{
        telaPerguntas = new telaDePerguntas(this, 1, opcoes->getQtdDeQuestoes());
        telaPerguntas->exec();
    }

    if(!telaPerguntas->ok){
        show();
    }else {
    //adicionar uma função de adicionar a pontuação
    login_user->getUser()->addPontuacao(telaPerguntas->pontuacaoDoQuiz);
    show();
    }
}
