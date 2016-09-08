#ifndef CONEXAODB_H
#define CONEXAODB_H
#include <iostream>
#include <cstdlib>
#include <ctime>

/*Biblioteca criada para separar a coneção do banco de dados das demais classes do programa;
 *Essa biblioteca armazena dados de um usuario e de uma pergunta temporariamente em uma estrutura de dados
 *respectivamente DADOS_DE_USUARIOS e DADOS_DE_PERGUNTAS;
 *As funções consultarPergunta() e consultarUsuario() conectam ao banco de dados e retornam dados desses usuarios
 */

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

struct DADOS_DE_USUARIO {
    int id;
    std::string nome;
    std::string loginName;
    std::string senha;
    std::string tipo;
    std::string instituicao;
    std::string curso;
    int rank;
    int pontuacao;
};

DADOS_DE_USUARIO consultarUsuario(std::string loginName, std::string senha);
DADOS_DE_PERGUNTAS consultaPergunta();

#endif // CONEXAODB_H
