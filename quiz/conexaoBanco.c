/*#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>


int main()
{
    MYSQL conexao;
    mysql_init(&conexao);
    if ( mysql_real_connect(&conexao, "endereço", "usuário", "senha", "banco de dados", 0, NULL, 0) )
    {
       printf("\nConexao ao banco realizada com sucesso!\n");
    }
    else
    {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }
    system("PAUSE");
    return(0);
}

*/
