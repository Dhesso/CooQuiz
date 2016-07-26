#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <stdlib.h>
#include "pergunta.h"

using namespace std;

class quiz
{
    public:
        //CONSTRUTOR
        quiz(int tipo, int nivel, int qtdqestoes);
        bool telaDePergunta(pergunta i, int a);

        //GUET'S
        int getPontuacao();
        vector<pergunta> getPerguntas();
        vector<pergunta> Perguntas;

    protected:
    private:

        //vector<pergunta> Perguntas;
        int pontuacao;
        string tipo;
        string nomeDoCurso;
        string nivel;
        int quantidadeDeQuestoes;

};

#endif // QUIZ_H
