#include "quiz.h"

int quiz::quizLivre(){
    return 0;
}

//IMPRIME UMA PERGUNTA NA TELA E RETORNA 1 SE RESPONDIDA CORRETAMENTE E 0 SE INCORRETA
bool quiz::telaDePergunta(pergunta i, int a){
    string resp;
    int indice = 0;
    do{
        cout << a  <<"_"  << i.getCabecalho() << endl<<endl;
        cout << "\n\na) " << i.getAlternativas(0)<<endl;
        cout << "\n\nb) " << i.getAlternativas(1)<<endl;
        cout << "\n\nc) " << i.getAlternativas(2)<<endl;
        cout << "\n\nd) " << i.getAlternativas(3)<<endl;
        cout << endl;
        cout << "Digite a letra correspondente a alternativa correta" << endl;
        cin >> resp;
        (resp=="a")?(indice = 0):
            (resp=="b")?(indice = 1):
                (resp=="c")?(indice = 2):
                    (resp=="d")?(indice = 3):
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
            for(int i=0 ; i < this->quantidadeDeQuestoes ; i++){
                //INSTANCIA PERGUNTAS

                string a[]= {"a", "b", "c", "d"};
                pergunta* p= new pergunta("cabecalho", a , "a");

                Perguntas.push_back(*p);
                //quiz::Perguntas[i] = *p;

                //QUARDA A PONTUAÇÃO

                this->pontuacao =+ (int)telaDePergunta(Perguntas[i],i+1);

                system("pause");
            }
            cout << "sua pontuacao e: "<< this->pontuacao<<endl;
            system("pause");
            break;
    }
}
