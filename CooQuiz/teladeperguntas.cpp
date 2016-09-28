#include "teladeperguntas.h"
#include "ui_teladeperguntas.h"

int telaDePerguntas::questaoAtual = 0;
telaDePerguntas::telaDePerguntas(QWidget *parent, int tipo, int qtdq) :
    QDialog(parent),
    ui(new Ui::telaDePerguntas)
{
    std::cout << "tela de quiz instanciado" <<std::endl;
    ui->setupUi(this);
    //garante pelo menos uma pergunta no quiz
    if(qtdq == 0)
        qtdq = 1;
    //instancia um objeto
    q = new quiz(tipo, qtdq);
    resposta = 4;
    pontuacaoDoQuiz = 0;
    questaoAtual = 0;
    iniciar();
}

telaDePerguntas::~telaDePerguntas()
{
    delete ui;
    delete q;
    std::cout << "tela de quiz destruida" << std::endl;
}

void telaDePerguntas::iniciar()
{
    //TRANSFORMA O INT questaoAtual em QString
    QString numeroDaQuestao;
    numeroDaQuestao.setNum(questaoAtual+1);

    //insere o texto da pergunta no textBrowser
    ui->textBrowser_questao->setText(QString::fromStdString("<h1><p>QUESTÃO ")+ numeroDaQuestao + QString::fromStdString(": </h1></p>") + QString::fromStdString
                                     (q->Perguntas[questaoAtual].getCabecalho()));
    ui->textBrowser_a->setText(QString::fromStdString(q->Perguntas[questaoAtual].getAlternativas(0)));
    ui->textBrowser_b->setText(QString::fromStdString(q->Perguntas[questaoAtual].getAlternativas(1)));
    ui->textBrowser_c->setText(QString::fromStdString(q->Perguntas[questaoAtual].getAlternativas(2)));
    ui->textBrowser_d->setText(QString::fromStdString(q->Perguntas[questaoAtual].getAlternativas(3)));
    questaoAtual ++;

}

void telaDePerguntas::on_pushButton_cancelar_clicked()
{
    ok = false;
    reject();
}

void telaDePerguntas::on_pushButton_corrigir_clicked()
{
    /* verifica se a resposta enviada pelo usuario está correta, se estiver
     * incrementa a pontuação e envia uma caixa de mensagem ao usuario informando,
     * do contrario não incrementa e envia outra caixa de mensagem informando
     */

    if(q->Perguntas[questaoAtual].getResposta(resposta)){
        pontuacaoDoQuiz ++;
        QMessageBox::information(this,"Correção","correto");
    }else {
        QMessageBox::information(this,"Correção","incorreto");
    }

    //CONTROLES DA BARA DE PROGRESSO
    ui->progressBar->setMaximum(q->Perguntas.size());
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(questaoAtual);

    /*VERIFICA SE AS QUESTÕES DISPONIVEIS FORAM USADAS, CASO SEJAM, FINALIZA O QUIZ
     * E ENVIA UMA MENSAGEM COM A PONTUAÇÃO */
    if(q->Perguntas.size() == questaoAtual){

        QMessageBox FimQuiz;
        QString a;
        a.setNum(pontuacaoDoQuiz);
        FimQuiz.information(this,"Fim do Quiz","<p>Fim do Quiz</p> Sua pontuação é: " + a);

        //verifica se a caixa de mensagem parou de ser exibida, caso sim, termina a execução do quiz
        if(FimQuiz.isHidden()){
            ok = true;
            accept();
        }

    }else{
        iniciar();
    }
}

void telaDePerguntas::on_radioButton_a_clicked()
{
    resposta = 0;
}

void telaDePerguntas::on_radioButton_b_clicked()
{
    resposta = 1;
}

void telaDePerguntas::on_radioButton_c_clicked()
{
    resposta = 2;
}

void telaDePerguntas::on_radioButton_d_clicked()
{
    resposta = 3;
}

