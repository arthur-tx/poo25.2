#ifndef PAIS_H
#define PAIS_H

#include <map>
#include "pessoa.h"
#include "atleta.h"
#include "medalha.h"
class Pais{
    private:
        string nome;
        string codigo;
        vector<Atleta*> atletas;
        vector<Medalha*> medalhas;

    public:
        Pais(const string& nome, const string& codigo);
        string getNome() const;
        string getCodigo() const;
        const vector<Atleta*>& getAtletas() const;
        const vector<Medalha*>& getMedalhas() const;
        void setNome(const string& novoNome);
        void setCodigo(const string& novoCodigo);
        void adicionarMedalha(Medalha* medalha);
        void adicionarAtleta(Atleta* atleta);
        void imprimirInformacoes() const;
};

#endif