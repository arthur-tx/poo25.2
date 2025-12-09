#ifndef ATLETA_H
#define ATLETA_H

#include "pessoa.h"
#include "modalidade.h"
#include "medalha.h"

class Atleta : public Pessoa {
private:
    int participacoes;
    vector<Medalha*> medalhas;
    
public:
   
   Atleta(const string& nome, const string& genero, int anoNascimento, Pais* pais, int participacoes);
    
    int getParticipacoes() const;
    const vector<Medalha*>& getMedalhas() const;
    void setParticipacoes(int novasParticipacoes);
    void adicionarMedalha(Medalha* medalha);

    void imprimirInformacoes() const override;
    std::string getTipo() const override;
};

#endif