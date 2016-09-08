#ifndef PERGUNTA_H
#define PERGUNTA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class pergunta
{
    public:
        //CONSTRUTORES:
        pergunta(string cid, string ccabecalho, string calternativas[], string crespota);

        //GETS:
        string getId();
        string getCabecalho();
        string getAlternativas(int i);
        string getCorreta();
        bool getResposta(int i);

    protected:
    private:
        //SET'S PARA CASCATEAMENTO
        pergunta &setid(string sid);
        pergunta &setcabecalho(string scabecalho);
        pergunta &setresposta(string sresposta);
        pergunta &setalternativas(string salternativas[]);
        //VARIAVEIS MEMBROS
        string id;
        string cabecalho;
        string alternativas[4];
        string resposta;
};

#endif // PERGUNTA_H
