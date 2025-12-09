#ifndef SISTEMA_OLIMPICO_H
#define SISTEMA_OLIMPICO_H

#include "pais.h"
#include "atleta.h"
#include "treinador.h"
#include "modalidade.h"
#include "medalha.h"

class SistemaOlimpico
{
private:
    vector<unique_ptr<Pais>> paises;
    vector<unique_ptr<Modalidade>> modalidade;
    vector<unique_ptr<Atleta>> atletas;
    vector<unique_ptr<Treinador>> treinadores;
    vector<unique_ptr<Medalha>> medalhas;

public:
    SistemaOlimpico();
    void cadastrarPais(const string &nome, const string &codigo);
    void cadastrarAtleta(const string &nome, const string &genero, int anoNascimento, const string &codigoPais);
    void cadastrarTreinador(const string &nome, const string &genero, int anoNascimento, const string &codigoPais);
    void criarModalidade(const string &codigo, const string &nome, int evento);
    void criarMedalha(const string &tipo, int ano, const string &codigoModalidade);

    Pais *buscarPais(const string &codigo) const;
    Atleta *buscarAtleta(const string &nome) const;
    Treinador *buscarTreinador(const string &nome) const;
    Modalidade *buscarModalidade(const string &codigo) const;
    Medalha *buscarMedalha(const string &tipo, int ano) const;

    bool associarAtletaPais(const string &nomeAtleta, const string &codigoPais);
    bool premiarAtletaMedalha(const string &nomeAtleta, const string &tipoMedalha, int ano, const string &codigoModalidade);

    void listarAtletasPorModalidade(const string &codigoModalidade) const;

    void carregarDados();
    void salvarDados() const;

    void listarPaises() const;
    void listarModalidades() const;
    void exibirQuadroMedalhas() const;
    void gerarRelatoriosEstatisticos() const ;
};

#endif