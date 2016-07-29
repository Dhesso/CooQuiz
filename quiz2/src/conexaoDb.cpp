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
MYSQL_RES *result; //result da query
MYSQL_FIELD *campos; // colunas do store result

//Thiago resolve isso aqui!:
char query[]="SELECT * FROM perguntas;"; //char contendo a query


DADOS_DE_PERGUNTAS consultaPergunta(){

    DADOS_DE_PERGUNTAS dados;

    mysql_init(&conect); // inicializa MYSQL conexão
    if ( mysql_real_connect(&conect, HOST, USER, PASS, DB, 0, NULL, 0) ) //começa a conexão e verifica se esta ok
    {
        cout << "Conexao ao banco realizada com sucesso!"<< endl;

        mysql_query(&conect,query);

        result = mysql_store_result(&conect);
        MYSQL_ROW linhas; //linhas do store result

        //Luan é aqui!!:
        srand(time(NULL));//semeia o rand
        int offset = rand() % ((int)mysql_num_rows(result)-1);

        linhas = mysql_fetch_row(result); //quarda a proxima linha do result
        mysql_data_seek(result, offset); //define a posição usual de linha do result
        linhas = mysql_fetch_row(result);

//obs: implementar um verificador do offset


        dados.id = linhas[0];
        dados.curso = linhas[1];
        dados.disciplina = linhas[2];
        string temp = linhas[3]; // armazena o valor da coluna 3
        dados.ch = atoi(temp.c_str()); //tranforma string em int e a armazena
        dados.tema = linhas[4];
        dados.dificuldade = linhas[5];
        dados.cabecalho = linhas[6];

        for (int i = 0; i < 4 ; i++) //preenche o vetor alternativas da estrutura
        {
            dados.alternativas[i] = linhas[7+i];
        }

        dados.respostaCorreta = linhas[11];

        dados.numeroDeLinhas = (int)mysql_num_rows(result)-1;
        dados.linhaSorteada = offset;

        return dados;
    }else
        {
            cout << "Falha na conexão" << endl;
            cout << mysql_errno(&conect) << ":" << mysql_error(&conect) << endl;

        }
    return dados;
}


//não usual:
/*
int getOffset(){
    mysql_init(&conect); // inicializa MYSQL conexão
    if ( mysql_real_connect(&conect, HOST, USER, PASS, DB, 0, NULL, 0) ) //começa a conexão e verifica se esta ok
    {
        cout << "Conexao ao banco realizada com sucesso!"<< endl;

        mysql_query(&conect,query);

        result = mysql_store_result(&conect);
        int of = (int)mysql_num_rows(result)-1;
        cout<< "of e: " << of <<endl;
        return of;
    }else
    {
        cout << "Falha na conexão" << endl;
        cout << mysql_errno(&conect) << ":" << mysql_error(&conect) << endl;

    }

    return 0;
}

}
using namespace std;

DADOS_DE_PERGUNTAS consultaPergunta(MYSQL_RES* res, std::string disciplina, std::string dificuldade, int offset){

    DADOS_DE_PERGUNTAS dados;
    MYSQL_ROW linhas; //linhas do store result
    linhas = mysql_fetch_row(res); //quarda a proxima linha do result
    mysql_data_seek(res, offset); //define a posição usual de linha do result
    linhas= mysql_fetch_row(res);

//obs: implementar um verificador do offset


    dados.id = linhas[0];
    dados.curso = linhas[1];
    dados.disciplina = linhas[2];
    string temp = linhas[3]; // armazena o valor da coluna 3
    dados.ch = atoi(temp.c_str()); //tranforma string em int e a armazena
    dados.tema = linhas[4];
    dados.dificuldade = linhas[5];
    dados.cabecalho = linhas[6];

    for (int i = 0; i < 4 ; i++) //preenche o vetor alternativas da estrutura
    {
        dados.alternativas[i] = linhas[7+i];
    }

    dados.respostaCorreta = linhas[11];

    return dados;
}

void desconectDB(MYSQL conect ,MYSQL_RES* res)
{
    mysql_free_result(res);
    mysql_close(&conect);

}


void conectDB(MYSQL conect)//ok
{

    mysql_init(&conect); // inicializa MYSQL conexão
    if ( mysql_real_connect(&conect, HOST, USER, PASS, DB, 0, NULL, 0) ) //começa a conexão e verifica se esta ok
    {
        cout << "Conexao ao banco realizada com sucesso!"<< endl;
    }else
        {
        cout << "Falha na conexão" << endl;
        cout << mysql_errno(&conect) << ":" << mysql_error(&conect) << endl;
        }
}

MYSQL_RES* inviteQuery(MYSQL conect,const char* query){

    if (mysql_query(&conect,query)) //VERIFICA SE A QUERY FOI REALIZADA
        {
            cout << mysql_error(&conect) << endl;
        }else{
              mysql_query(&conect,query);
              return mysql_store_result(&conect); // RETORNA O RESULT DA QUERY
             }
    return mysql_store_result(&conect);
}

*/
