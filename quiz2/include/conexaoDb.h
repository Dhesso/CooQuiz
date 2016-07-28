#ifndef CONEXAODB_H_INCLUDED
#define CONEXAODB_H_INCLUDED
#include <iostream>

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
};

DADOS_DE_PERGUNTAS consultaPergunta(int offset);
int getOffset();










/*

#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <iostream>



//DADOS DA CONEXÃO
#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "dbcooquiz"


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
};

DADOS_DE_PERGUNTAS consultaPergunta(MYSQL_RES* res, std::string disciplina, std::string dificuldade, int offset);

void desconectDB(MYSQL conect ,MYSQL_RES* res);

void conectDB(MYSQL conect);

MYSQL_RES* inviteQuery(MYSQL conect,const char* query);
*/

#endif // CONEXAODB_H_INCLUDED
