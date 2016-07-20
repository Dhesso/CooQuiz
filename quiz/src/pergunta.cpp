#include "pergunta.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

//CONSTRUTOR

pergunta:: pergunta(string cabecalho, string alternativas[], string resposta){
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

string pergunta::getCorreta(){
return this->resposta;
}
string pergunta::getCabecalho(){
    return this->cabecalho;
}
string pergunta::getAlternativas(int i){
    return this->alternativas[i];
}


