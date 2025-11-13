#ifndef MEDALHA_H
#define MEDALHA_H

#include "modalidade.h"
#include "atleta.h"

class Modalidade;
class Atleta;

class Medalha {
public:
    string tipo;
    int ano;
    Modalidade* modalidade;
    Atleta* atletaPremiado;

    Medalha(const string& tipo, int ano, Modalidade* modalidade, Atleta* atleta);

    string getTipo() const;
    int getAno() const;
    Modalidade* getModalidade() const;
    Atleta* getAtletaPremiado() const;

    void setTipo(const string& novoTipo);
    void setAno(int novoAno);

    void imprimirInformacoes() const;
};

#endif