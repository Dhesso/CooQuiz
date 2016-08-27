#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include "pergunta.h"
#include "conexaoDb.h"

using namespace std;

class quiz
{
    public:
        //CONSTRUTOR
        quiz(int tipo, int nivel, int qtdqestoes);

        //METODOS
        bool telaDePergunta(pergunta i, int a);

        //GUET'S
        int getPontuacao();
        vector<pergunta> getPerguntas();

        //VARIAVEIS MEMBROS
        vector<pergunta> Perguntas;

    protected:
    private:

        //SET'S COM CASCATEAMENTO
        quiz &setPerguntas();
        quiz &setPontuacao(int spontuacao);
        quiz &setQuantidadeDeQuestoes(int squantidadedequestoes);
        quiz &setTipo(string stipo);
        quiz &setNomeDoCurso(string snomedocurso);
        quiz &setNivel(string snivel);
        //VARIAVEIS MEMBROS
        int pontuacao;
        int quantidadeDeQuestoes;

        string tipo;
        string nomeDoCurso;
        string nivel;


};

#endif // QUIZ_H
