#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include "conexaodb.h"

class usuario
{
public:
    usuario(std::string cusername, std::string csenha);
    ~usuario();
    int getId();
    std::string getName();
    std::string getUserName();
    std::string getTipo();
    std::string getInstituicao();
    std::string getCurso();
    int getPontuacao();
    int getRank();

    void addPontuacao(int i);

private:

    usuario &setInstituicao(std::string sinstituicao);
    usuario &setCurso(std::string scurso);
    usuario &incrementRank();
    usuario &setPontuacao(int spontuacao);

    const int id;
    const std::string nome;
    const std::string userName;
    const std::string tipo;
    std::string instituicao;
    std::string curso;
    int pontuacao;
    int rank=0;

};

#endif // USUARIO_H
