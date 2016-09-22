#ifndef OPICOESDOQUIZ_H
#define OPICOESDOQUIZ_H

#include <QDialog>

namespace Ui {
class OpicoesDoQuiz;
}

class OpicoesDoQuiz : public QDialog
{
    Q_OBJECT

public:
    explicit OpicoesDoQuiz(QWidget *parent = 0);
    ~OpicoesDoQuiz();
    QString getCurso();
    QString getDisciplina();
    QString getConteudo();
    int getQtdDeQuestoes();

    //set's
    void setLabelTipo(std::string tipo);

    bool ok;

private slots:
    void on_pushButton_cancelar_clicked();

    void on_pushButton_comecar_clicked();

private:

    Ui::OpicoesDoQuiz *ui;
    int QtdDeQuestoes;
    QString curso;
    QString disciplina;
    QString conteudo;

    std::vector<std::string> listaDeCursos;
    std::vector<std::string> listaDeDisciplinas;
    std::vector<std::string> listaDeConteudos;
    std::vector<std::string> listaDeNiveis;

};

#endif // OPICOESDOQUIZ_H
