#ifndef QUIZ_H
#define QUIZ_H
#include "pergunta.h"
#include "conexaodb.h"

/* classe de quiz geral, responsavel por organizar as questoes que serão utilizadas em cada quiz.
 * tambem é classe mãe para outros tipos de quiz
*/

class quiz
{
    public:
        //CONSTRUTOR
        quiz(int tipo, int qtdqestoes=1);

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
        quiz &setConteudo(std::string sconteudo);
        quiz &setNivel(std::string snivel);

        //VARIAVEIS MEMBROS
        int pontuacao=0;
        int quantidadeDeQuestoes;

        string tipo;
        string nomeDoCurso;
        string disciplina;
        string conteudo;
        string nivel;


};

#endif // QUIZ_H
