#include "usuario.h"

usuario::usuario(std::string cusername, std::string csenha):
    id(consultarUsuario(cusername,csenha).id),
    nome(consultarUsuario(cusername,csenha).nome),
    userName(consultarUsuario(cusername,csenha).loginName),
    tipo(consultarUsuario(cusername,csenha).tipo)
{
    DADOS_DE_USUARIO dados = consultarUsuario(cusername,csenha);
    setInstituicao(dados.instituicao).setCurso(dados.curso).setPontuacao(dados.pontuacao);
}

//GET'S

std::string usuario::getName(){
    return this->nome;
}
std::string usuario::getUserName(){
    return this->userName;
}
std::string usuario::getTipo(){
    return this->tipo;
}
std::string usuario::getInstituicao(){
    return this->instituicao;
}
std::string usuario::getCurso(){
    return this->curso;
}
int usuario::getRank(){
    return this->rank;
}

//SET'S

usuario &usuario::setInstituicao(std::string sinstituicao){
    this->instituicao = sinstituicao;
    return *this;
}
usuario &usuario::setCurso(std::string scurso){
    curso = scurso;
    return *this;
}
usuario &usuario::setPontuacao(int spontuacao){
    this->pontuacao = spontuacao;
    return *this;
}
usuario &usuario::incrementRank(){
    return *this;
}
