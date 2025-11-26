#ifndef TREINADOR_H
#define TREINADOR_H

#include "pessoa.h"
#include "atleta.h"

class Treinador : public Pessoa
{
private:
    vector<Atleta *> atletasTreinados;

public:
    Treinador(const string &nome, const string &genero, int anoNascimento, Pais *pais);
    const vector<Atleta *> &getAtletasTreinados() const;
    void adicionarAtletaTreinado(Atleta *atleta);
    void imprimirInformacoes() const override;
    string getTipo() const override;
};

#endif