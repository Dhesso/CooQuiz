#include "conexaoDb.h"
#include <QCoreApplication>
#include <QtSql>
#include <QString>
#include <iostream>
#define q2c(string) string.toStdString() //macro

//DADOS DA CONEXÃO
#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "dbcooquiz"

using namespace std;

//CONECTA AO BANCO DE DADOS E RETORNA DADOS DE PERGUNTAS
DADOS_DE_PERGUNTAS consultaPergunta(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //instancia objetos QsqlDatabase com valores retornados pelo tipo de banco do drive QSqlDatabase::addDatabase("QMYSQL")
    db.setHostName(HOST); //seta o endereço de coneção
    db.setUserName(USER); //seta o nome de usuario no banco
    db.setPassword(PASS); //seta a senha para acessar o banco
    db.setDatabaseName(DB); //seta o nome da base de dados

    DADOS_DE_PERGUNTAS dados; //estrutura de dados utilizada para guardar os dados de usuario temporariamente

    if(db.open()) { //db.open() inicia a conexão e retorna true se estiver ok
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl; //mensagem para depuração

        QSqlQuery query; //objeto que manipula as querys

        if(query.exec("SELECT * FROM perguntas;")){ //executa uma solicitação ao banco de dados, consultando a tabela perguntas


            srand(time(NULL));//semeia o rand

            int offset = rand() % query.record().count(); //ramdomiza uma linha aleatoria da consulta a tabela de perguntas

            query.first(); //indica que a consulta iniciara a partir da primeira linha;
            query.isActive(); //torna a consulta ativa -não é necessario mas é mais indicado-

            for (int i = 0; i<=offset; i++){//utiliza a linha obtida por offset para escolher a linha a ser utilizada
                query.next(); //obtem a proxima linha da consulta
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
        std::cout << "voce esta conectado a " << q2c(db.hostName()) << std::endl;

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
