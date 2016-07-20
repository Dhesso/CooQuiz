#include <iostream>
#include <string>
#include <stdlib.h>
#include "pergunta.h"
#include "quiz.h"
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <stdio.h>


using namespace std;

int main()
{
/*
    MYSQL conexao;
    mysql_init(&conexao);
    if ( mysql_real_connect(&conexao, "localhost", "root", "", "quiz", 0, NULL, 0) )
    {
       printf("\nConexao ao banco realizada com sucesso!\n");
    }
    else
    {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }
    system("PAUSE");
  */
    quiz a(1,1,1);
    return 0;
}
