#ifndef PERGUNTA_H
#define PERGUNTA_H

#include <iostream>

using namespace std;

class pergunta
{
    public:
        //CONSTRUTORES:
        pergunta(string cabecalho, string alternativas[], string respota);
        //GETS:
        string getCabecalho();
        string getAlternativas(int i);
        string getCorreta();
        bool getResposta(int i);

    protected:
    private:
        string cabecalho;
        string alternativas[4];
        string resposta;
};

#endif // PERGUNTA_H
