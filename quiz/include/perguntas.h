#ifndef PERGUNTA_H
#define PERGUNTA_H


class pergunta
{
    public:
        pergunta(string cabecalho, string alternativas[4], string respota);
    protected:
    private:
        string cabecalho;
        string alternativas[4];
        const string opcoes[4]={"a","b","c","d"};
        string resposta;
};

#endif // PERGUNTA_H
