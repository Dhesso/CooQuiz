#ifndef QUIZ_H
#define QUIZ_H


#include <vector>
#include "pergunta.h"
#include "conexaoDb.h"

class quiz
{
    public:
        //CONSTRUTOR
        quiz(int tipo, int qtdqestoes);

        //METODOS
        bool telaDePergunta(pergunta i, int a);

        //quiz &aumentaPontuação();
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
        quiz &setTipo(std::string stipo);
        quiz &setNomeDoCurso(std::string snomedocurso);
        quiz &setNivel(std::string snivel);

        //VARIAVEIS MEMBROS
        int pontuacao=0;
        int quantidadeDeQuestoes;

        string tipo;
        string nomeDoCurso;
        string nivel;


};

#endif // QUIZ_H
