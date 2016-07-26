#include "conexaoDb.h"
#include <string>

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

void desconectDB(MYSQL_RES* res, MYSQL conect)
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

MYSQL_RES* inviteQuery(MYSQL conexao, char query[]){

    if (mysql_query(&conexao,query)) //VERIFICA SE A QUERY FOI REALIZADA
        {
            cout << mysql_error(&conexao) << endl;
        }else{
              mysql_query(&conexao,query);
              return mysql_store_result(&conexao); // RETORNA O RESULT DA QUERY
             }
}
