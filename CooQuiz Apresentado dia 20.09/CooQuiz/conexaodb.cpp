#include "conexaoDb.h"
#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <QString>
#define q2c(string) string.toStdString() //macro

//DADOS DA CONEXÃO
#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "dbcooquiz"

using namespace std;

//CONCATENA STRINGS'S
char* concatenaString(char szSrc1[], char szSrc2[]){
    int nTargetSize = strlen(szSrc1) + strlen(szSrc2) + 1;
    char* pszTarget = new char[nTargetSize];
    int nT;
    for(nT = 0 ; szSrc1[nT] != '\0' ; nT++){
        pszTarget[nT] = szSrc1[nT];
    }
    for(int nS=0; szSrc2[nS] != '\0'; nT++, nS++){
        pszTarget[nT] = szSrc2[nS];
    }
    pszTarget[nT]='\0';

    return pszTarget;
}

//CONECTA AO BANCO DE DADOS E RETORNA DADOS DE PERGUNTAS
DADOS_DE_PERGUNTAS consultaPergunta(char curso[], char disciplina[], char tema[], char nivel[]){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados

    DADOS_DE_PERGUNTAS dados; //estrutura de dados utilizada para guardar os dados de usuario temporariamente

    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        //Concatena o texto da query;
        char* texto = concatenaString("SELECT * FROM perguntas WHERE curso LIKE '", curso);
        texto = concatenaString(texto, "' AND disciplina LIKE '");
        texto = concatenaString(texto, disciplina);
        texto = concatenaString(texto, "' AND tema LIKE '");
        texto = concatenaString(texto, tema);
        texto = concatenaString(texto, "' AND dificuldade = '");
        texto = concatenaString(texto, nivel);
        texto = concatenaString(texto, "'");

        QString textQuery = texto;

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas
            QSqlRecord rec = query.record();
            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            srand(time(NULL));//semeia o rand
            int offset = 1 + rand() % query.size(); //ramdomiza uma linha aleatoria da consulta a tabela de perguntas

            std::cout << "a quantidade de linha na consulta e: " << query.size() << std::endl; //debug
            std::cout << "a linha sorteada foi: " << offset << std::endl;//debug

            for (int i = 1; i <= offset; i++){//utiliza a linha obtida por offset para escolher a linha a ser utilizada
                query.next(); //obtem a proxima linha da consulta
                std::cout << "linha usada na consulta foi: " << i << std::endl;//debug
            }

            dados.id = query.value(0).toString().toStdString();//armazena o id da pergunta na estrutura dados
            dados.curso = query.value(1).toString().toStdString(); //armazena o curso da pergunta na estrutura dados
            dados.disciplina = query.value(2).toString().toStdString();//armazena a disciplina da pergunta na estrutura dados
            string temp = query.value(3).toString().toStdString(); // armazena o valor da coluna 3 (string ch) em temp
            dados.ch = atoi(temp.c_str()); //tranforma string de temp em int e a armazena
            dados.tema = query.value(4).toString().toStdString();; //armazena o tema da pergunta na estrutura dados
            dados.dificuldade = query.value(5).toString().toStdString(); //armazena a dificuldade da pergunta na estrutura dados
            dados.cabecalho = query.value(6).toString().toStdString(); //armazena o cabecalho da pergunta e estrutura dados

            for (int i = 0; i < 4 ; i++) //preenche o vetor alternativas na estrutura
                {
                    dados.alternativas[i] =query.value(7+i).toString().toStdString();
                }

            dados.respostaCorreta = query.value(11).toString().toStdString(); //armazena a resposta da pergunta na estrutura dados

            dados.numeroDeLinhas = (int)query.record().count(); //armazena o numero de linhas da consulta
            dados.linhaSorteada = offset; //armazena a linha sorteada da consulta

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db

            return dados;
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
    return dados;
}

//CONECTA AO BANCO DE DADOS E RETORNA DADOS DE USUARIOS
DADOS_DE_USUARIO consultarUsuario(std::string loginName, std::string senha){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST);
    db.setUserName(USER);
    db.setPassword(PASS);
    db.setDatabaseName(DB);

    DADOS_DE_USUARIO dados; //estrutura que armazena temporariamente os dados dos usuarios

    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok

        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //debug

        QSqlQuery query; //objeto que controla a consulta ao db
        QString squery; //objeto que manipula strings, classe propria do qt

        //EXECUTA A CONSULTA A TABELA USUARIOS E VERIFICA SE HÁ UM USUARIO COM O loginName NA TABELA

        query.exec(squery.fromStdString("SELECT * FROM usuarios WHERE loginName IN('" + loginName + "')"));
        query.first();//indica a primeira linha da consulta
        query.isActive();//torna a consulta ativa;

        if(query.value("loginName").toString().toStdString() == loginName && query.value(3).toString().toStdString() == senha){//verifica se o login e senha estão corretos

            dados.id = query.value(0).toInt();
            dados.nome = query.value(1).toString().toStdString(); //armazena o nome do usuario na estrutura
            dados.loginName = query.value(2).toString().toStdString(); //armazena o loginName do usuario na estrutura
            dados.senha = query.value(3).toString().toStdString(); //armazena a senha do usuario na estrutura
            dados.instituicao = query.value(4).toString().toStdString();//armazena a instituição do usuario na estrutura
            dados.curso = query.value(5).toString().toStdString();; //armazena o curso do usuario na estrutura
            dados.tipo = query.value(6).toString().toStdString(); //armazena o tipo de usuario na estrutura
            std::string temp = query.value(7).toString().toStdString();//armazena a pontuação em forma de estring temporariamente
            dados.pontuacao = atoi(temp.c_str()); //converte string em inteiro
            temp = query.value(8).toString().toStdString(); // armazena o hanck em forma de estring temporariamente;
            dados.rank = atoi(temp.c_str()); //converte string em int e armazena em rank

            query.clear(); //limpa a query
            db.close(); //fecha a conexão
            return dados;
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//linha para a depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
    return dados;
}

void consultarListadeCursos(std::vector<std::string> &listaDeCursos)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados



    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        QString textQuery = "SELECT `curso` FROM `perguntas` GROUP BY `curso`";

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas

            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            while(query.next()){
                listaDeCursos.push_back(query.value("curso").toString().toStdString());
            }

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
}

void consultarListadeDisciplinas(std::vector<string> &listaDeDisciplina)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados



    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        QString textQuery = "SELECT `disciplina` FROM `perguntas` GROUP BY `disciplina`";

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas

            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            while(query.next()){
                listaDeDisciplina.push_back(query.value("disciplina").toString().toStdString());
            }

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
}

void consultarListaDeConteudos(std::vector<string> &listaDeConteudos)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados



    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        QString textQuery = "SELECT `tema` FROM `perguntas` GROUP BY `tema`";

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas

            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            while(query.next()){
                listaDeConteudos.push_back(query.value("tema").toString().toStdString());
            }

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
}

void consultarListaDeNivel(std::vector<string> &ListaDeNiveis)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados



    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        QString textQuery = "SELECT `dificuldade` FROM `perguntas` GROUP BY `dificuldade`";

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas

            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            while(query.next()){
                ListaDeNiveis.push_back(query.value("dificuldade").toString().toStdString());
            }

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
}

void consultarRank(std::vector<std::string> &ListaDoRank)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados



    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        QString textQuery = "SELECT `loginName`, `pontuacao` FROM `usuarios` ORDER BY `pontuacao`";

        std::cout << textQuery.toStdString() << std::endl; //depuração

        if(query.exec(textQuery)){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas

            std::cout << "a query executada foi :" << query.executedQuery().toStdString() << std::endl;

            while(query.next()){
                ListaDoRank.push_back(query.value("dificuldade").toString().toStdString());
            }

            query.clear(); //limpa a consulta
            db.close(); //fecha a conexão com o db
        }else
        {
            std::cout << "erro na query. :(" << std::endl << q2c(query.lastError().text()) << std::endl;//mensagem para depuração
        }

        db.close();

    }else{
        std::cout << "Erro na conexao :(" << std::endl << q2c(db.lastError().text()) << std::endl;
        db.close();
        }
}
