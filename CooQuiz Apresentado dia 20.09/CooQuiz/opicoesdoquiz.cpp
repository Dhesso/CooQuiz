#include "opicoesdoquiz.h"
#include "ui_opicoesdoquiz.h"
#include "conexaodb.h"

OpicoesDoQuiz::OpicoesDoQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpicoesDoQuiz)
{
    ui->setupUi(this);

    consultarListadeCursos(listaDeCursos);
    consultarListadeDisciplinas(listaDeDisciplinas);
    consultarListaDeConteudos(listaDeConteudos);
    consultarListaDeNivel(listaDeNiveis);

    for(int i=0; i != listaDeCursos.size(); i++){
        ui->comboBox_curso->addItem(QString::fromStdString(listaDeCursos[i]));
    }
    for(int i=0; i!= listaDeDisciplinas.size(); i++){
        ui->comboBox_disciplina->addItem(QString::fromStdString(listaDeDisciplinas[i]));
    }
    for(int i=0; i!= listaDeConteudos.size(); i++){
        ui->comboBox_conteudo->addItem(QString::fromStdString(listaDeConteudos[i]));
    }
    for(int i=0; i!= listaDeNiveis.size(); i++){
        ui->comboBox_dificuldade->addItem(QString::fromStdString(listaDeNiveis[i]));
    }

}

OpicoesDoQuiz::~OpicoesDoQuiz()
{
    delete ui;
}

//get's

QString OpicoesDoQuiz::getCurso()
{
    return curso;
}

QString OpicoesDoQuiz::getDisciplina()
{
    return disciplina;
}

QString OpicoesDoQuiz::getConteudo()
{
    return conteudo;
}

int OpicoesDoQuiz::getQtdDeQuestoes()
{
    return QtdDeQuestoes;
}


//set's

void OpicoesDoQuiz::setLabelTipo(std::string tipo)
{
    ui->label_Livre->setText(QString::fromStdString(tipo));
}

//slots

void OpicoesDoQuiz::on_pushButton_cancelar_clicked()
{
    ok = false;
    reject();
}

void OpicoesDoQuiz::on_pushButton_comecar_clicked()
{
    curso = ui->comboBox_curso->currentText();
    disciplina = ui->comboBox_disciplina->currentText();
    conteudo = ui->comboBox_conteudo->currentText();
    QtdDeQuestoes = ui->spinBox_QtDdeQuestoes->text().toInt();
    ok = true;
    accept();
}
