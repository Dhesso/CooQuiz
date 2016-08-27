#include "conexaoDb.h"

#include <string>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <iostream>

//DADOS DA CONEXÃO
#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "dbcooquiz"

using namespace std;

MYSQL conect; //variavel MYSQL
MYSQL_RES *result; //resultado da query
MYSQL_FIELD *campos; // colunas do store result

//Thiago resolve isso aqui!:
char query[]="SELECT * FROM perguntas;"; //char contendo a query


DADOS_DE_PERGUNTAS consultaPergunta(){

    DADOS_DE_PERGUNTAS dados;

    mysql_init(&conect); // inicializa MYSQL conexão
    if ( mysql_real_connect(&conect, HOST, USER, PASS, DB, 0, NULL, 0) ) //faz a conexão e verifica se esta ok
    {
        cout << "Conexao ao banco realizada com sucesso!"<< endl;

        mysql_query(&conect,query);//faz a conculta ao banco de dados

        result = mysql_store_result(&conect); //guarda a consulta na strutura result
        MYSQL_ROW linhas; //linhas do store result

        //Luan é aqui!!:
        srand(time(NULL));//semeia o rand
        int offset = rand() % ((int)mysql_num_rows(result)-1); //ramdomiza uma linha aleatoria da consulta

        linhas = mysql_fetch_row(result); //quarda a proxima linha do resultado da consulta
        mysql_data_seek(result, offset); //define a posição usual de linha do resultado da consulta
        linhas = mysql_fetch_row(result); //guarda a proxima linha do resultado da consulta

//obs: implementar um verificador do offset


        dados.id = linhas[0]; //armazena o id da pergunta na estrutura dados
        dados.curso = linhas[1]; //armazena o curso da pergunta na estrutura dados
        dados.disciplina = linhas[2];//armazena a disciplina da pergunta na estrutura dados
        string temp = linhas[3]; // armazena o valor da coluna 3 (string ch) em temp
        dados.ch = atoi(temp.c_str()); //tranforma string de temp em int e a armazena
        dados.tema = linhas[4]; //armazena o tema da pergunta na estrutura dados
        dados.dificuldade = linhas[5]; //armazena a dificuldade da pergunta na estrutura dados
        dados.cabecalho = linhas[6]; //armazena o cabecalho da pergunta e estrutura dados

        for (int i = 0; i < 4 ; i++) //preenche o vetor alternativas na estrutura
        {
            dados.alternativas[i] = linhas[7+i];
        }

        dados.respostaCorreta = linhas[11]; //armazena a resposta da pergunta na estrutura dados

        dados.numeroDeLinhas = (int)mysql_num_rows(result)-1; //armazena o numero de linhas da consulta
        dados.linhaSorteada = offset; //armazena a linha sorteada da consulta

        return dados;

    }else
        {
            cout << "Falha na conexão" << endl;
            cout << mysql_errno(&conect) << ":" << mysql_error(&conect) << endl;

        }
    return dados;
}

