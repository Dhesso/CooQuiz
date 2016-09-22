#include "quiz.h"

//CONSTRUTOR

quiz::quiz(int tipo, int qtdqestoes)
{
    switch (tipo){
        case 1:
            setTipo("livre").setQuantidadeDeQuestoes(qtdqestoes).setPontuacao(0).setPerguntas();
            break;
        case 2:
            setTipo("Provão").setQuantidadeDeQuestoes(30).setPontuacao(0).setPerguntas();
            break;
    }
}

//GET'S
int quiz::getPontuacao()
{
return this->pontuacao;
}

vector<pergunta> quiz::getPerguntas()
{
return Perguntas;
}

//SET'S COM CASCATEAMENTO
quiz &quiz::setPontuacao(int spontuacao)
{
    this->pontuacao = spontuacao;
    return *this;
}
quiz &quiz::setQuantidadeDeQuestoes(int squantidadedequestoes)
{
    this->quantidadeDeQuestoes = squantidadedequestoes;
    return *this;
}
quiz &quiz::setTipo(std::string stipo)
{
    this->tipo = stipo;
    return *this;
}
quiz &quiz::setNomeDoCurso(std::string snomedocurso)
{
    this->nomeDoCurso = snomedocurso;
    return *this;
}

quiz &quiz::setConteudo(string sconteudo)
{
    this->conteudo = sconteudo;
    return *this;
}

quiz &quiz::setNivel(std::string snivel)
{
    this->nivel = snivel;
    return *this;
}

//VERIFICA REPETIÇÕES DE PERGUNTAS E PREENCHE O VETOR PERGUNTAS COM OBJETOS PERGUNTAS
quiz &quiz::setPerguntas(){

    DADOS_DE_PERGUNTAS dados; //estrutura de dados para armazer temporariamente os dados das perguntas

    for(int i=0 ; i < this->quantidadeDeQuestoes ; i++){

        bool repete;
        do{
            dados = consultaPergunta(); //cria a estrutura dados com dados da linha do db
            cout << "linha apos dados" << endl; //depuração

            if (Perguntas.empty()) //verifica se o vetor Perguntas está vazio
            {
                this->Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta)));// faz uma copia do objeto para o vetor perguntas
                cout << "primeira pergunta inserida" <<endl; //depuração
            }else{

                int tamanhoDoVector = this->Perguntas.size(); //armazena o tamanho do vetor
                for(int j=0 ; j < tamanhoDoVector ; j++) //percore o vetor Pergunta
                {
                    if(Perguntas[j].getId() == dados.id) //verifica se há perguntas repetidas no vetor
                    {
                        repete = true;
                        cout << "houve repetição" << endl; //depuração
                        break;
                    }else
                        {
                        repete = false;
                        cout << "não houve repetição" << endl << endl; //depuração
                        }
                }

                    if(repete == false) // caso não haja perguntas repetidas guarda a nova pergunta
                    {
                        Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta)));
                        cout << "proxima pergunta realizada com sucesso" << endl; //depuração
                    }
            }
        }while(repete == true);

        cout << "fim do laco" << endl; //depuração
    }
    return *this;
}
