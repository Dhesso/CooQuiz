#ifndef TELADEPERGUNTAS_H
#define TELADEPERGUNTAS_H

#include <QDialog>
#include "quiz.h"
#include <QMessageBox>

namespace Ui {
class telaDePerguntas;
}

class telaDePerguntas : public QDialog
{
    Q_OBJECT

public:
    explicit telaDePerguntas(QWidget *parent = 0, int tipo = 1, int qtdq = 2);
    ~telaDePerguntas();
    void iniciar();

    //variavel que indica a saida de tela
    int pontuacaoDoQuiz;
    bool ok;
    static int questaoAtual;

private slots:
    void on_pushButton_cancelar_clicked();

    void on_pushButton_corrigir_clicked();

    void on_radioButton_a_clicked();

    void on_radioButton_b_clicked();

    void on_radioButton_c_clicked();

    void on_radioButton_d_clicked();

private:
    Ui::telaDePerguntas *ui;
    quiz *q;
    int resposta;
};

#endif // TELADEPERGUNTAS_H
