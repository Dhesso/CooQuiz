#include "pergunta.h"

//CONSTRUTOR

pergunta::pergunta(string cid, string ccabecalho, string calternativas[], string cresposta){

    setid(cid).setcabecalho(ccabecalho).setalternativas(calternativas).setresposta(cresposta);

}
//SET'S
pergunta &pergunta::setid(string sid){
    this->id=sid;
    return *this;
}
pergunta &pergunta::setcabecalho(string scabecalho){
    this->cabecalho = scabecalho;
    return *this;
}
pergunta &pergunta::setresposta(string sresposta){
    this->resposta = sresposta;
    return *this;
}

pergunta &pergunta::setalternativas(string salternativas[]){

    //PREENCHE O VETOR ALTERNATIVAS
    for(int i=0; i<4; i++){

        this->alternativas[i]=salternativas[i];
    }

    //RAMDOMIZA AS POSIÇÕES DO VETOR ALTERNATIVAS[]
    srand(time(NULL));
    for(int i=0; i<4; i++){
        int r = rand() % 3;
        string temp = this->alternativas[i];
        this->alternativas[i] = this->alternativas[r];
        this->alternativas[r] = temp;
    }
    return *this;
}


//GETERES

//retorna se a resposta passa é a alternativa correta
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
