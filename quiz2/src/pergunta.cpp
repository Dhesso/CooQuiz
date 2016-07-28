#include "pergunta.h"

//CONSTRUTOR

pergunta:: pergunta(string id, string cabecalho, string alternativas[], string resposta){

    //SET'S VALORES DOS ATRIBUTOS
    this->id = id;
    this->cabecalho = cabecalho;
    this->resposta = resposta;

    //PREENCHE O VETOR alternativas[]
    for(int i=0; i<4; i++){

        this->alternativas[i]=alternativas[i];
    }

    //RAMDOMIZA AS POSIÇÕES DO VETOR ALTERNATIVAS[]
    srand(time(NULL));
    for(int i=0; i<4; i++){
        int r = rand() % 3;
        string temp = this->alternativas[i];
        this->alternativas[i] = this->alternativas[r];
        this->alternativas[r] = temp;
    }
}

//GETERES

bool pergunta::getResposta(int i){

    if(this->resposta == this->alternativas[i]){
        return true;
    }else{
        return false;
    }
}
string pergunta::getId(){
return this->id;
}
string pergunta::getCorreta(){
return this->resposta;
}
string pergunta::getCabecalho(){
    return this->cabecalho;
}
string pergunta::getAlternativas(int i){
    return this->alternativas[i];
}



