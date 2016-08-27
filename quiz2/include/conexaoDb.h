#ifndef CONEXAODB_H_INCLUDED
#define CONEXAODB_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct DADOS_DE_PERGUNTAS {
    std::string id;
    std::string curso;
    std::string disciplina;
    unsigned int ch;
    std::string tema;
    std::string dificuldade;
    std::string cabecalho;
    std::string alternativas[4];
    std::string respostaCorreta;
    int numeroDeLinhas;
    int linhaSorteada;
};

DADOS_DE_PERGUNTAS consultaPergunta();

int getOffset();

#endif // CONEXAODB_H_INCLUDED
