#ifndef QUIZ_H
#define QUIZ_H
#include <stdlib.h>
#include <vector>
#include "pergunta.h"

class quiz
{
    public:
        quiz(int tipo, int nivel, int qtdqestoes);
        int quizLivre();
        bool telaDePergunta(pergunta i, int a);
    protected:
    private:
        vector<pergunta> Perguntas;
        int pontuacao;
        string tipo;
        string nivel;
        int quantidadeDeQuestoes;

};

#endif // QUIZ_H
