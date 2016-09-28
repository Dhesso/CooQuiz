#include "usuario.h"

//construtor
usuario::usuario(std::string cusername, std::string csenha):
    //inicializa os membros constantes conectando ao banco de dados
    id(consultarUsuario(cusername,csenha).id),
    nome(consultarUsuario(cusername,csenha).nome),
    userName(consultarUsuario(cusername,csenha).loginName),
    tipo(consultarUsuario(cusername,csenha).tipo)
{
    //seta os membros não constantes dos usuarios
    DADOS_DE_USUARIO dados = consultarUsuario(cusername,csenha);
    setInstituicao(dados.instituicao).setCurso(dados.curso).setPontuacao(dados.pontuacao);
}

usuario::~usuario()
{
    std::cout << "usuario destruido" <<std::endl;
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

int usuario::getPontuacao()
{
    return pontuacao;
}

int usuario::getRank(){
    return this->rank;
}

//SET'S

void usuario::addPontuacao(int i)
{
  pontuacao += i;
}

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
