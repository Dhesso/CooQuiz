#include "quiz.h"

//CONSTRUTOR

quiz::quiz(int tipo, int qtdqestoes=1)
{
    switch (tipo){
        case 1:
            setTipo("livre").setQuantidadeDeQuestoes(qtdqestoes).setPontuacao(0).setPerguntas();
            system("pause");
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
return this->Perguntas;
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
quiz &quiz::setNivel(std::string snivel)
{
    this->nivel = snivel;
    return *this;
}

//VERIFICA REPETIÇÕES DE PERGUNTAS E PREENCHE O VETOR PERGUNTAS COM OBJETOS PERGUNTAS
quiz &quiz::setPerguntas(){

    int offset=0; //inteiro para controlar a lina da consulta

    cout << offset << endl;

    DADOS_DE_PERGUNTAS dados; //estrutura de dados para armazer temporariamente os dados das perguntas


    for(int i=0 ; i < this->quantidadeDeQuestoes ; i++){

        bool repete;
        do{
            dados = consultaPergunta(); //cria a estrutura dados com dados da linha do db
            cout << "linha apos dados" << endl;

            if (Perguntas.empty()) //verifica se o vetor Perguntas está vazio
            {
                this->Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta)));// faz uma copia do objeto para o vetor perguntas
                cout << "primeira pergunta inserida" <<endl;
            }else{

                int tamanhoDoVector = this->Perguntas.size(); //armazena o tamanho do vetor
                for(int j=0 ; j < tamanhoDoVector ; j++) //percore o vetor Pergunta
                {
                    if(Perguntas[j].getId() == dados.id) //verifica se há perguntas repetidas no vetor
                    {
                        repete = true;
                        cout << "houve repetição" << endl;
                        break;
                    }else
                        {
                        repete = false;
                        cout << "não houve repetição" << endl << endl;
                        }
                }

                    if(repete == false) // caso não haja perguntas repetidas guarda a nova pergunta
                    {
                        this->Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta)));
                        cout << "proxima pergunta realizada com sucesso" << endl;
                    }
            }
        }while(repete == true);

        cout << "fim do laco" << endl;
    }
    return *this;
}

//IMPRIME UMA PERGUNTA NA TELA E RETORNA 1 SE RESPONDIDA CORRETAMENTE E 0 SE INCORRETA
bool quiz::telaDePergunta(pergunta i, int a){
    std::string resposta;
    int indice = 0;
    do{
        cout << a  <<"_"  << i.getCabecalho() << endl<<endl;
        cout << "\n\na) " << i.getAlternativas(0)<<endl;
        cout << "\n\nb) " << i.getAlternativas(1)<<endl;
        cout << "\n\nc) " << i.getAlternativas(2)<<endl;
        cout << "\n\nd) " << i.getAlternativas(3)<<endl;
        cout << endl;
        cout << "Digite a letra correspondente a alternativa correta" << endl;
        cin >> resposta;
        (resposta=="a")?(indice = 0):
            (resposta=="b")?(indice = 1):
                (resposta=="c")?(indice = 2):
                    (resposta=="d")?(indice = 3):
                        (indice = 4);
        (indice==4)?(cout<<"opicao invalida"<<endl):(i.getResposta(indice) == true)?(cout<<"correto"<<endl):(cout<<"incorreto"<<endl);
        system("pause");
        system("cls");
    }while(indice==4);
    return i.getResposta(indice);
}

