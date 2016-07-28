
#include "quiz.h"

//IMPRIME UMA PERGUNTA NA TELA E RETORNA 1 SE RESPONDIDA CORRETAMENTE E 0 SE INCORRETA
bool quiz::telaDePergunta(pergunta i, int a){
    string resposta;
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

quiz::quiz(int tipo, int nivel, int qtdqestoes=1)
{
    //INSTANCIA OBJETOS DO TIPO PERGUNTA E IMPRIME A PONTUAÇÃO DO USUARIO
    switch (tipo){
        case 1:
            this->tipo = "livre";
            this->quantidadeDeQuestoes = qtdqestoes;
            this->pontuacao = 0;

            int offset=0;//inteiro para controlar a lina da consulta

            cout << offset << endl;

            DADOS_DE_PERGUNTAS dados; //estrutura de dados para armazer temporariamente os dados das perguntas


            for(int i=0 ; i < this->quantidadeDeQuestoes ; i++)
            {
                srand(time(NULL));//semeia o rand
                bool repete;
                do{
                offset = rand() % (getOffset()+1);
                cout << "o offseet escolido foi : " << offset << endl; //randomisa a linha da consulta do banco
                dados = consultaPergunta(offset); //cria a estrutura com dados da linha do db
                cout << "linha apos dados" << endl;
                if (Perguntas.empty()) //verifica se o vetor Perguntas está vazio
                { // quarda os valores da estrutura em um objeto
                   // pergunta* ppergunta = new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta);
                    this->Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta))); // faz uma copia do objeto para o vetor pergun
                    //delete ppergunta;
                    //ppergunta = NULL;
                    cout << "primeira pergunta inserida" <<endl;

                }else{
                    cout << "apos else" << endl;
                    int tamanhoDoVector = this->Perguntas.size();
                        for(int j=0 ; j < tamanhoDoVector ; j++) //percore o vetor Pergunta
                        {

                            if(Perguntas[j].getId() == dados.id) //verifica se há perguntas repetidas no vetor
                                {
                                repete = true;
                                cout << "houve repetição" << endl;
                                break;
                                cout << "apos break" << endl;
                                }else
                                    {
                                        repete = false;
                                        cout << "não houve repetição" << endl << endl;
                                    }
                        }

                        if(repete == false) // caso não haja perguntas repetidas guarda a nova pergunta
                        {
                            //pergunta* ppergunta = new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta);
                            this->Perguntas.push_back(*(new pergunta(dados.id, dados.cabecalho , dados.alternativas , dados.respostaCorreta)));
                            cout << "proxima pergunta realizada com sucesso" << endl;
                        }
                    }
                }while(repete == true);

                cout << "fim do laco" << endl;

              }

            //cout << "sua pontuacao e: "<< this->pontuacao<<endl;
            system("pause");
            break;
    }
}

int quiz::getPontuacao(){
return this->pontuacao;
}

vector<pergunta> quiz::getPerguntas(){
return this->Perguntas;
}
