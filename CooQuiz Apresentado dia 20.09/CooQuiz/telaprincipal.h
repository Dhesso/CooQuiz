#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "login.h"
#include "opicoesdoquiz.h"
#include "teladeperguntas.h"

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void on_actionQuiz_Livre_triggered();

private:
    Ui::TelaPrincipal *ui;
    Login *login_user;
    OpicoesDoQuiz *opcoes;
    telaDePerguntas *telaPerguntas;
};

#endif // TELAPRINCIPAL_H
