#ifndef PERGUNTA_H
#define PERGUNTA_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class pergunta
{
    public:
        //CONSTRUTORES:
        pergunta(string id, string cabecalho, string alternativas[], string respota);
        //GETS:
        string getId();
        string getCabecalho();
        string getAlternativas(int i);
        string getCorreta();
        bool getResposta(int i);

    protected:
    private:

        string id;
        string cabecalho;
        string alternativas[4];
        string resposta;
};

#endif // PERGUNTA_H
