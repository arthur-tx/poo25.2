#ifndef FUNCAO_H
#define FUNCAO_H

#include "pais.h"
#include "atleta.h"
#include "treinador.h"
#include "modalidade.h"
#include "medalha.h"
#include "SistemaOlimpico.h"
#include "pessoa.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include <cctype> // Necessário para toupper

using namespace std;

// [NOVO] Função auxiliar para padronizar textos em maiúsculo
string paraMaiusculo(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
    return texto;
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE PESSOA
// ==========================================
Pessoa ::Pessoa(const string &nome, const string &genero, int anoNascimento, Pais *pais)
    : nome(nome), genero(genero), anoNascimento(anoNascimento), pais(pais) {}
string Pessoa ::getNome() const
{
    return nome;
}
void Pessoa ::setNome(const string &nome)
{
    this->nome = nome;
}
string Pessoa ::getGenero() const
{
    return genero;
}
void Pessoa ::setGenero(const string &genero)
{
    this->genero = genero;
}
Pais *Pessoa ::getPais() const
{
    return pais;
}
void Pessoa ::setPais(Pais *novoPais)
{
    pais = novoPais;
}
int Pessoa ::getAnoNascimento() const
{
    return anoNascimento;
}
void Pessoa ::setAnoNascimento(int anoNascimento)
{
    this->anoNascimento = anoNascimento;
}

const vector<Modalidade *> &Pessoa ::getModalidades() const
{
    return modalidades;
}
void Pessoa ::adicionarModalidade(Modalidade *modalidade)
{
    modalidades.push_back(modalidade);
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE MODALIDADE
// ==========================================
Modalidade ::Modalidade(const string &codigo, const string &nome, int evento)
    : codigo(codigo), nome(nome), evento(evento) {}

string Modalidade ::getCodigo() const
{
    return codigo;
}
void Modalidade ::setCodigo(const string &novoCodigo)
{
    codigo = novoCodigo;
}
string Modalidade ::getNome() const
{
    return nome;
}

void Modalidade ::setNome(const string &novoNome)
{
    nome = novoNome;
}
int Modalidade ::getEvento() const
{
    return evento;
}
void Modalidade ::setEvento(int novoEvento)
{
    evento = novoEvento;
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE PAIS
// ==========================================
Pais ::Pais(const string &nome, const string &codigo)
    : nome(nome), codigo(codigo) {}
string Pais ::getNome() const
{
    return nome;
}
void Pais ::setNome(const string &novoNome)
{
    nome = novoNome;
}
string Pais ::getCodigo() const
{
    return codigo;
}
void Pais ::setCodigo(const string &novoCodigo)
{
    codigo = novoCodigo;
}
const vector<Atleta *> &Pais ::getAtletas() const
{
    return atletas;
}
const vector<Medalha *> &Pais ::getMedalhas() const
{
    return medalhas;
}
void Pais ::adicionarMedalha(Medalha *medalha)
{
    medalhas.push_back(medalha);
}
void Pais ::adicionarAtleta(Atleta *atleta)
{
    atletas.push_back(atleta);
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE ATLETA
// ==========================================
Atleta ::Atleta(const string &nome, const string &genero, int anoNascimento, Pais *pais, int participacoes)
    : Pessoa(nome, genero, anoNascimento, pais), participacoes(participacoes) {}

int Atleta ::getParticipacoes() const
{
    return participacoes;
}
void Atleta ::setParticipacoes(int novasParticipacoes)
{
    participacoes = novasParticipacoes;
}
const vector<Medalha *> &Atleta ::getMedalhas() const
{
    return medalhas;
}
void Atleta ::adicionarMedalha(Medalha *medalha)
{
    medalhas.push_back(medalha);
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE MEDALHA
// ==========================================
Medalha ::Medalha(const string &tipo, int ano, Modalidade *modalidade, Atleta *atleta)
    : tipo(tipo), ano(ano), modalidade(modalidade), atletaPremiado(atleta) {}
string Medalha ::getTipo() const
{
    return tipo;
}
void Medalha ::setTipo(const string &novoTipo)
{
    tipo = novoTipo;
}
int Medalha ::getAno() const
{
    return ano;
}
void Medalha ::setAno(int novoAno)
{
    ano = novoAno;
}
Modalidade *Medalha ::getModalidade() const
{
    return modalidade;
}
Atleta *Medalha ::getAtletaPremiado() const
{
    return atletaPremiado;
}

// ==========================================
// IMPLEMENTAÇÃO DA CLASSE TREINADOR
// ==========================================
Treinador ::Treinador(const string &nome, const string &genero, int anoNascimento, Pais *pais)
    : Pessoa(nome, genero, anoNascimento, pais) {}
const vector<Atleta *> &Treinador ::getAtletasTreinados() const
{
    return atletasTreinados;
}
void Treinador ::adicionarAtletaTreinado(Atleta *atleta)
{
    atletasTreinados.push_back(atleta);
}

// ==========================================
// IMPLEMENTAÇÃO DO SISTEMA OLIMPICO
// ==========================================
SistemaOlimpico ::SistemaOlimpico() {}

void SistemaOlimpico ::cadastrarPais(const string &nome, const string &codigo)
{
    // [ALTERADO] Padroniza código para busca e cadastro
    string codMaiusculo = paraMaiusculo(codigo);

    for (const auto &pais : paises)
    {
        if (pais->getCodigo() == codMaiusculo)
        {
            cout << "País com código " << codMaiusculo << " já cadastrado." << endl;
            return;
        }
    }
    paises.push_back(make_unique<Pais>(nome, codMaiusculo));
    cout << "País " << nome << " cadastrado com sucesso." << endl;
}

void SistemaOlimpico ::cadastrarAtleta(const string &nome, const string &genero, int anoNascimento, const string &codigoPais)
{
    // [ALTERADO] Padroniza genero e codigo pais
    string codPaisMaiusculo = paraMaiusculo(codigoPais);
    string genMaiusculo = paraMaiusculo(genero);

    Pais *pais = buscarPais(codPaisMaiusculo);
    if (!pais)
    {
        cout << "País com código " << codPaisMaiusculo << " nao encontrado." << endl;
        return;
    }
    // verificar se o atleta já existe (pelo Nome)
    for (const auto &atleta : atletas)
    {
        if (atleta->getNome() == nome) // Nome mantemos original (case sensitive pode ser desejado)
        {
            cout << "Atleta com nome " << nome << " já cadastrado." << endl;
            return;
        }
    }

    auto novoAtleta = make_unique<Atleta>(nome, genMaiusculo, anoNascimento, pais, 0);
    pais->adicionarAtleta(novoAtleta.get());
    atletas.push_back(move(novoAtleta));
    cout << "Atleta " << nome << " cadastrado com sucesso." << endl;
}

void SistemaOlimpico ::cadastrarTreinador(const string &nome, const string &genero, int anoNascimento, const string &codigoPais)
{
    // [ALTERADO] Padroniza genero e codigo pais
    string codPaisMaiusculo = paraMaiusculo(codigoPais);
    string genMaiusculo = paraMaiusculo(genero);

    Pais *pais = buscarPais(codPaisMaiusculo);
    if (!pais)
    {
        cout << "País com código " << codPaisMaiusculo << " nao encontrado." << endl;
        return;
    }
    for (const auto &treinador : treinadores)
    {
        if (treinador->getNome() == nome)
        {
            cout << "Treinador com nome " << nome << " já cadastrado." << endl;
            return;
        }
    }
    treinadores.push_back(make_unique<Treinador>(nome, genMaiusculo, anoNascimento, pais));
    cout << "Treinador " << nome << " cadastrado com sucesso." << endl;
}

void SistemaOlimpico ::criarModalidade(const string &codigo, const string &nome, int evento)
{
    // [ALTERADO] Padroniza código da modalidade
    string codMaiusculo = paraMaiusculo(codigo);

    for (const auto &mod : modalidade)
    {
        if (mod->getCodigo() == codMaiusculo)
        {
            cout << "Modalidade com código " << codMaiusculo << " já existe." << endl;
            return;
        }
    }
    modalidade.push_back(make_unique<Modalidade>(codMaiusculo, nome, evento));
    cout << "Modalidade " << nome << " criada com sucesso." << endl;
}

void SistemaOlimpico ::criarMedalha(const string &tipo, int ano, const string &codigoModalidade)
{
    // [ALTERADO] Padroniza tipo da medalha e codigo da modalidade
    string tipoMaiusculo = paraMaiusculo(tipo);
    string codModMaiusculo = paraMaiusculo(codigoModalidade);

    Modalidade *mod = buscarModalidade(codModMaiusculo);
    if (!mod)
    {
        cout << "Modalidade com código " << codModMaiusculo << " nao encontrada." << endl;
        return;
    }
    medalhas.push_back(make_unique<Medalha>(tipoMaiusculo, ano, mod, nullptr));
    cout << "Medalha " << tipoMaiusculo << " criada com sucesso para o ano " << ano << "." << endl;
}

Pais *SistemaOlimpico ::buscarPais(const string &codigo) const
{
    // [ALTERADO] Busca insensível a maiúsculas/minúsculas
    string codBusca = paraMaiusculo(codigo);
    for (const auto &pais : paises)
    {
        if (pais->getCodigo() == codBusca)
        {
            return pais.get();
        }
    }
    return nullptr;
}

Atleta *SistemaOlimpico ::buscarAtleta(const string &nome) const
{
    // Nota: Busca por nome geralmente é exata, mas se quiser flexibilizar,
    // pode usar paraMaiusculo aqui também. Por enquanto, mantive exata.
    for (const auto &atleta : atletas)
    {
        if (atleta->getNome() == nome)
        {
            return atleta.get();
        }
    }
    return nullptr;
}

Treinador *SistemaOlimpico ::buscarTreinador(const string &nome) const
{
    for (const auto &treinador : treinadores)
    {
        if (treinador->getNome() == nome)
        {
            return treinador.get();
        }
    }
    return nullptr;
}

Modalidade *SistemaOlimpico ::buscarModalidade(const string &codigo) const
{
    // [ALTERADO] Busca padronizada
    string codBusca = paraMaiusculo(codigo);
    for (const auto &mod : modalidade)
    {
        if (mod->getCodigo() == codBusca)
        {
            return mod.get();
        }
    }
    return nullptr;
}

Medalha *SistemaOlimpico ::buscarMedalha(const string &tipo, int ano) const
{
    // [ALTERADO] Busca padronizada
    string tipoBusca = paraMaiusculo(tipo);
    for (const auto &med : medalhas)
    {
        if (med->getTipo() == tipoBusca && med->getAno() == ano)
        {
            return med.get();
        }
    }
    return nullptr;
}

bool SistemaOlimpico ::associarAtletaPais(const string &nomeAtleta, const string &codigoPais)
{
    // [ALTERADO] Codigo pais padronizado na busca
    Atleta *atleta = buscarAtleta(nomeAtleta);
    Pais *pais = buscarPais(paraMaiusculo(codigoPais));
    if (!atleta || !pais)
    {
        return false;
    }
    atleta->setPais(pais);
    pais->adicionarAtleta(atleta);
    return true;
}

bool SistemaOlimpico ::premiarAtletaMedalha(const string &nomeAtleta, const string &tipoMedalha, int ano, const string &codigoModalidade)
{
    // [ALTERADO] Padronização dos termos de busca
    string tipoBusca = paraMaiusculo(tipoMedalha);
    string codModBusca = paraMaiusculo(codigoModalidade);

    Atleta *atleta = buscarAtleta(nomeAtleta); 
    Medalha *medalha = buscarMedalha(tipoBusca, ano);
    Modalidade *modalidade = buscarModalidade(codModBusca);

    if (!atleta || !medalha || !modalidade)
    {
        cout << "Atleta (" << nomeAtleta << "), medalha ou modalidade nao encontrada." << endl;
        return false;
    }

    // Associar a medalha ao atleta
    medalha->setAtletaPremiado(atleta);
    atleta->adicionarMedalha(medalha);
    atleta->setParticipacoes(atleta->getParticipacoes() + 1);
    atleta->getPais()->adicionarMedalha(medalha);
    cout << "Atleta " << atleta->getNome() << " premiado com medalha " << tipoBusca << " no ano " << ano << "." << endl;

    return true;
}

void SistemaOlimpico ::listarAtletasPorModalidade(const string &codigoModalidade) const
{
    // [ALTERADO] Padronização
    string codBusca = paraMaiusculo(codigoModalidade);
    Modalidade *modalidade = buscarModalidade(codBusca);

    if (!modalidade)
    {
        cout << "Modalidade com código " << codBusca << " nao encontrada." << endl;
        return;
    }
    cout << "Atletas na modalidade " << modalidade->getNome() << ":" << endl;
    for (const auto &atleta : atletas)
    {
        const auto &modalidadesAtleta = atleta->getModalidades();
        for (const auto &modalidadeAtleta : modalidadesAtleta)
        {
            if (modalidadeAtleta->getCodigo() == codBusca)
            {
                atleta->imprimirInformacoes();
                break;
            }
        }
    }
}

void SistemaOlimpico::listarPaises() const
{
    cout << "Países cadastrados:" << endl;
    for (const auto &pais : paises)
    {
        cout << "- " << pais->getNome() << " (" << pais->getCodigo() << ")" << endl;
    }
}

void SistemaOlimpico::listarModalidades() const
{
    cout << "Modalidades cadastradas:" << endl;
    for (const auto &modalidadesAtleta : modalidade)
    {
        cout << "- " << modalidadesAtleta->getNome() << " (" << modalidadesAtleta->getCodigo() << ") - Evento: " << modalidadesAtleta->getEvento() << endl;
    }
}

void SistemaOlimpico::carregarDados()
{
    ifstream arquivo("dados_olimpicos.txt");

    if (!arquivo.is_open())
    {
        cout << "Arquivo de dados nao encontrado. Criando novo arquivo..." << endl;
        return;
    }

    string linha;
    string secaoAtual;

    while (getline(arquivo, linha))
    {
        if (linha.empty())
            continue;

        if (linha[0] == '[' && linha[linha.length() - 1] == ']')
        {
            secaoAtual = linha;
            continue;
        }

        stringstream ss(linha);
        string token;

        if (secaoAtual == "[PAISES]")
        {
            string nome, codigo;
            getline(ss, nome, ';');
            getline(ss, codigo, ';');
            cadastrarPais(nome, codigo); // Já chama paraMaiusculo internamente
        }
        else if (secaoAtual == "[ATLETAS]")
        {
            string nome, genero, anoStr, codigoPais, participacoesStr;
            getline(ss, nome, ';');
            getline(ss, genero, ';');
            getline(ss, anoStr, ';');
            getline(ss, codigoPais, ';');
            getline(ss, participacoesStr, ';'); 

            // Como usamos make_unique direto aqui sem passar pelo cadastrarAtleta,
            // precisamos aplicar paraMaiusculo manualmente aqui também:
            string codPaisUpper = paraMaiusculo(codigoPais);
            string genUpper = paraMaiusculo(genero);

            Pais *pais = buscarPais(codPaisUpper);
            if (pais)
            {
                auto novoAtleta = make_unique<Atleta>(nome, genUpper, stoi(anoStr), pais, stoi(participacoesStr));
                pais->adicionarAtleta(novoAtleta.get());
                atletas.push_back(move(novoAtleta));
            }
        }
        else if (secaoAtual == "[TREINADORES]")
        {
            string nome, genero, anoStr, codigoPais;
            getline(ss, nome, ';');
            getline(ss, genero, ';');
            getline(ss, anoStr, ';');
            getline(ss, codigoPais, ';');

            string codPaisUpper = paraMaiusculo(codigoPais);
            string genUpper = paraMaiusculo(genero);

            Pais *pais = buscarPais(codPaisUpper);
            if (pais)
            {
                treinadores.push_back(make_unique<Treinador>(nome, genUpper, stoi(anoStr), pais));
            }
        }
        else if (secaoAtual == "[MODALIDADES]")
        {
            string codigo, nome, eventoStr;
            getline(ss, codigo, ';');
            getline(ss, nome, ';');
            getline(ss, eventoStr, ';');
            
            // cadastrar manual, aplica uppercase
            modalidade.push_back(make_unique<Modalidade>(paraMaiusculo(codigo), nome, stoi(eventoStr)));
        }
        else if (secaoAtual == "[MEDALHAS]")
        {
            string tipo, anoStr, codigoModalidade, nomeAtleta;
            getline(ss, tipo, ';');
            getline(ss, anoStr, ';');
            getline(ss, codigoModalidade, ';');
            getline(ss, nomeAtleta, ';');

            string codModUpper = paraMaiusculo(codigoModalidade);
            string tipoUpper = paraMaiusculo(tipo);

            Modalidade *modalidadePtr = buscarModalidade(codModUpper);
            Atleta *atleta = buscarAtleta(nomeAtleta); 

            if (modalidadePtr)
            {
                auto novaMedalha = make_unique<Medalha>(tipoUpper, stoi(anoStr), modalidadePtr, atleta);
                if (atleta)
                {
                    atleta->adicionarMedalha(novaMedalha.get());
                    atleta->getPais()->adicionarMedalha(novaMedalha.get());
                }
                medalhas.push_back(move(novaMedalha));
            }
        }
        else if (secaoAtual == "[ATLETAS_MODALIDADES]")
        {
            string nomeAtleta, codigoModalidade;
            getline(ss, nomeAtleta, ';');
            getline(ss, codigoModalidade, ';');

            Atleta *atleta = buscarAtleta(nomeAtleta); 
            Modalidade *modalidadePtr = buscarModalidade(paraMaiusculo(codigoModalidade));

            if (atleta && modalidadePtr)
            {
                atleta->adicionarModalidade(modalidadePtr);
            }
        }
        else if (secaoAtual == "[TREINADORES_ATLETAS]")
        {
            string nomeTreinador, nomeAtleta;
            getline(ss, nomeTreinador, ';');
            getline(ss, nomeAtleta, ';');

            Treinador *treinador = buscarTreinador(nomeTreinador);
            Atleta *atleta = buscarAtleta(nomeAtleta);

            if (treinador && atleta)
            {
                treinador->adicionarAtletaTreinado(atleta);
            }
        }
    }

    arquivo.close();
    cout << "Dados carregados com sucesso! " << endl;
    cout << "- Países: " << paises.size() << endl;
    cout << "- Atletas: " << atletas.size() << endl;
    cout << "- Treinadores: " << treinadores.size() << endl;
    cout << "- Modalidades: " << modalidade.size() << endl;
    cout << "- Medalhas: " << medalhas.size() << endl;
}

void SistemaOlimpico::salvarDados() const
{
    ofstream arquivo("dados_olimpicos.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao criar arquivo de dados!" << endl;
        return;
    }

    // Salvar países
    arquivo << "[PAISES]" << endl;
    for (const auto &pais : paises)
    {
        arquivo << pais->getNome() << ";" << pais->getCodigo() << ";" << endl;
    }
    arquivo << endl;

    // Salvar atletas
    arquivo << "[ATLETAS]" << endl;
    for (const auto &atleta : atletas)
    {
        arquivo << atleta->getNome() << ";"
                << atleta->getGenero() << ";"
                << atleta->getAnoNascimento() << ";"
                << (atleta->getPais() ? atleta->getPais()->getCodigo() : "NONE") << ";"
                << atleta->getParticipacoes() << ";" << endl;
    }
    arquivo << endl;

    // Salvar treinadores
    arquivo << "[TREINADORES]" << endl;
    for (const auto &treinador : treinadores)
    {
        arquivo << treinador->getNome() << ";"
                << treinador->getGenero() << ";"
                << treinador->getAnoNascimento() << ";"
                << (treinador->getPais() ? treinador->getPais()->getCodigo() : "NONE") << ";" << endl;
    }
    arquivo << endl;

    // Salvar modalidades
    arquivo << "[MODALIDADES]" << endl;
    for (const auto &mod : modalidade)
    {
        arquivo << mod->getCodigo() << ";" << mod->getNome() << ";" << mod->getEvento() << ";" << endl;
    }
    arquivo << endl;

    // Salvar medalhas
    arquivo << "[MEDALHAS]" << endl;
    for (const auto &medalha : medalhas)
    {
        arquivo << medalha->getTipo() << ";"
                << medalha->getAno() << ";"
                << (medalha->getModalidade() ? medalha->getModalidade()->getCodigo() : "NONE") << ";"
                << (medalha->getAtletaPremiado() ? medalha->getAtletaPremiado()->getNome() : "NONE") << ";" << endl;
    }
    arquivo << endl;

    // Salvar associações atletas-modalidades
    arquivo << "[ATLETAS_MODALIDADES]" << endl;
    for (const auto &atleta : atletas)
    {
        for (const auto &modalidade : atleta->getModalidades())
        {
            arquivo << atleta->getNome() << ";" << modalidade->getCodigo() << ";" << endl;
        }
    }
    arquivo << endl;

    // Salvar associações treinadores-atletas
    arquivo << "[TREINADORES_ATLETAS]" << endl;
    for (const auto &treinador : treinadores)
    {
        for (const auto &atleta : treinador->getAtletasTreinados())
        {
            arquivo << treinador->getNome() << ";" << atleta->getNome() << ";" << endl;
        }
    }

    arquivo.close();
    cout << "Dados salvos com sucesso no arquivo 'dados_olimpicos.txt'!" << endl;
    cout << "- Países salvos: " << paises.size() << endl;
    cout << "- Atletas salvos: " << atletas.size() << endl;
    cout << "- Treinadores salvos: " << treinadores.size() << endl;
    cout << "- Modalidades salvas: " << modalidade.size() << endl;
    cout << "- Medalhas salvas: " << medalhas.size() << endl;
}

// Para Atleta
void Atleta::imprimirInformacoes() const
{
    cout << "Atleta: " << getNome() << " | Gênero: " << getGenero()
         << " | Ano Nascimento: " << getAnoNascimento()
         << " | País: " << (getPais() ? getPais()->getNome() : "Nenhum")
         << " | Participações: " << participacoes
         << " | Medalhas: " << medalhas.size() << endl;
}

std::string Atleta::getTipo() const
{
    return "Atleta";
}

// Para Treinador
void Treinador::imprimirInformacoes() const
{
    cout << "Treinador: " << getNome() << " | Gênero: " << getGenero()
         << " | Ano Nascimento: " << getAnoNascimento()
         << " | País: " << (getPais() ? getPais()->getNome() : "Nenhum")
         << " | Atletas Treinados: " << atletasTreinados.size() << endl;
}

string Treinador::getTipo() const
{
    return "Treinador";
}

// Para Medalha
void Medalha::imprimirInformacoes() const
{
    cout << "Medalha: " << tipo << " | Ano: " << ano
         << " | Modalidade: " << (modalidade ? modalidade->getNome() : "Nenhuma")
         << " | Atleta: " << (atletaPremiado ? atletaPremiado->getNome() : "Nenhum") << endl;
}

void Medalha::setAtletaPremiado(Atleta *atleta) {
    atletaPremiado = atleta;
}

// Para Modalidade
void Modalidade::imprimirInformacoes() const
{
    cout << "Modalidade: " << nome << " | Código: " << codigo
         << " | Evento: " << evento << endl;
}

// Para Pais
void Pais::imprimirInformacoes() const
{
    cout << "País: " << nome << " | Código: " << codigo
         << " | Atletas: " << atletas.size()
         << " | Medalhas: " << medalhas.size() << endl;
}

void SistemaOlimpico::exibirQuadroMedalhas() const
{
    struct LinhaQuadro
    {
        Pais *pais;
        int ouro;
        int prata;
        int bronze;
        int total;
    };

    vector<LinhaQuadro> ranking;

    for (const auto &paisPtr : paises)
    {
        Pais *p = paisPtr.get();
        if (!p)
            continue;

        int ouro = 0, prata = 0, bronze = 0;

        for (Medalha *m : p->getMedalhas())
        {
            if (!m)
                continue;

            // [ALTERADO] Garante comparação correta
            string tipo = paraMaiusculo(m->getTipo());

            if (tipo == "OURO")
                ouro++;
            else if (tipo == "PRATA")
                prata++;
            else if (tipo == "BRONZE")
                bronze++;
        }

        LinhaQuadro linha{p, ouro, prata, bronze, ouro + prata + bronze};
        ranking.push_back(linha);
    }

    std::sort(ranking.begin(), ranking.end(),
              [](const LinhaQuadro &a, const LinhaQuadro &b)
              {
                  if (a.ouro != b.ouro)
                      return a.ouro > b.ouro;
                  if (a.prata != b.prata)
                      return a.prata > b.prata;
                  if (a.bronze != b.bronze)
                      return a.bronze > b.bronze;
                  return a.total > b.total;
              });

    cout << "==== QUADRO DE MEDALHAS ====\n";
    for (const auto &linha : ranking)
    {
        cout << linha.pais->getNome()
             << " (" << linha.pais->getCodigo() << ")"
             << " - Ouro: " << linha.ouro
             << " | Prata: " << linha.prata
             << " | Bronze: " << linha.bronze
             << " | Total: " << linha.total
             << '\n';
    }
    cout << "============================\n";
}

// ---------------------------------------------------------
// IMPLEMENTAÇÃO DO RELATÓRIO DE ESTATÍSTICAS (PONTO EXTRA)
// ---------------------------------------------------------

void SistemaOlimpico::gerarRelatoriosEstatisticos() const {
    cout << "\n==========================================" << endl;
    cout << "      RELATORIO ESTATISTICO OLIMPICO      " << endl;
    cout << "==========================================" << endl;

    if (atletas.empty() || paises.empty()) {
        cout << "[AVISO] Dados insuficientes para gerar estatisticas." << endl;
        cout << "Cadastre paises e atletas primeiro." << endl;
        return;
    }

    // 1. ESTATISTICAS DE ATLETAS (Idade Media)
    double somaIdades = 0;
    int anoAtual = 2024;
    for (const auto& atleta : atletas) {
        somaIdades += (anoAtual - atleta->getAnoNascimento());
    }
    double mediaIdade = (atletas.empty()) ? 0 : somaIdades / atletas.size();

    cout << "1. ESTATISTICAS DE ATLETAS:" << endl;
    cout << "   - Total de Atletas: " << atletas.size() << endl;
    cout << "   - Idade Media: " << mediaIdade << " anos" << endl;

    // 2. DESEMPENHO POR PAIS (MAIS E MENOS MEDALHAS)
    Pais* topPais = nullptr;
    size_t maxMedalhas = 0;
    Pais* bottomPais = nullptr;
    size_t minMedalhas = -1; // Valor maximo de size_t

    for (const auto& p : paises) {
        size_t qtd = p->getMedalhas().size();
        if (qtd >= maxMedalhas) {
            maxMedalhas = qtd;
            topPais = p.get();
        }
        if (qtd < minMedalhas) {
            minMedalhas = qtd;
            bottomPais = p.get();
        }
    }

    cout << "\n2. DESEMPENHO GERAL POR PAIS:" << endl;
    if (topPais && maxMedalhas > 0) {
        cout << "   - Pais com MAIS medalhas: " << topPais->getNome() 
             << " (" << maxMedalhas << " medalhas)" << endl;
    } else {
        cout << "   - Nenhum pais possui medalhas ainda." << endl;
    }
    if (bottomPais) {
        cout << "   - Pais com MENOS medalhas: " << bottomPais->getNome() 
             << " (" << minMedalhas << " medalhas)" << endl;
    }

    // 3. POPULARIDADE DAS MODALIDADES
    map<string, int> contagemModalidades;
    for (const auto& atleta : atletas) {
        for (const auto& mod : atleta->getModalidades()) {
            contagemModalidades[mod->getNome()]++;
        }
    }

    string nomeTopMod = "Nenhuma";
    int maxAtletasMod = 0;
    for (auto const& par : contagemModalidades) {
        if (par.second > maxAtletasMod) {
            maxAtletasMod = par.second;
            nomeTopMod = par.first;
        }
    }

    cout << "\n3. POPULARIDADE DAS MODALIDADES:" << endl;
    if (maxAtletasMod > 0) {
        cout << "   - Modalidade com mais atletas: " << nomeTopMod 
             << " (" << maxAtletasMod << " inscritos)" << endl;
    } else {
        cout << "   - Nenhuma associacao atleta-modalidade feita." << endl;
    }

    // 4. DESTAQUES INDIVIDUAIS POR PAIS
    cout << "\n4. DESTAQUES INDIVIDUAIS POR PAIS:" << endl;
    for (const auto& paisPtr : paises) {
        Pais* p = paisPtr.get();
        Atleta* atletaDestaque = nullptr;
        size_t maiorNumMedalhas = 0;

        for (const auto& atleta : p->getAtletas()) {
            size_t numMedalhas = atleta->getMedalhas().size();
            if (numMedalhas > maiorNumMedalhas) {
                maiorNumMedalhas = numMedalhas;
                atletaDestaque = atleta;
            }
        }

        cout << "   - " << p->getNome() << ": ";
        if (atletaDestaque && maiorNumMedalhas > 0) {
            cout << atletaDestaque->getNome() << " (" << maiorNumMedalhas << " medalhas)" << endl;
        } else {
            cout << "(Sem medalhistas)" << endl;
        }
    }

    // 5. ESTATISTICAS DE TREINADORES
    cout << "\n5. ESTATISTICAS DE TREINADORES:" << endl;
    Treinador* topTreinadorQtd = nullptr;
    size_t maxQtdAtletas = 0;
    Treinador* topTreinadorMedalhas = nullptr;
    size_t maxTotalMedalhasTreinador = 0;

    for (const auto& treinador : treinadores) {
        size_t qtdAtletas = treinador->getAtletasTreinados().size();
        if (qtdAtletas >= maxQtdAtletas) {
            maxQtdAtletas = qtdAtletas;
            topTreinadorQtd = treinador.get();
        }
        size_t somaMedalhas = 0;
        for (const auto& atleta : treinador->getAtletasTreinados()) {
            somaMedalhas += atleta->getMedalhas().size();
        }
        if (somaMedalhas >= maxTotalMedalhasTreinador) {
            maxTotalMedalhasTreinador = somaMedalhas;
            topTreinadorMedalhas = treinador.get();
        }
    }

    if (topTreinadorQtd && maxQtdAtletas > 0) {
        cout << "   - Treinador com mais atletas: " << topTreinadorQtd->getNome()
             << " (" << maxQtdAtletas << " atletas)" << endl;
    } else {
        cout << "   - Treinador com mais atletas: Nenhum registro." << endl;
    }
    if (topTreinadorMedalhas && maxTotalMedalhasTreinador > 0) {
        cout << "   - Treinador com mais medalhas: " << topTreinadorMedalhas->getNome()
             << " (" << maxTotalMedalhasTreinador << " medalhas somadas)" << endl;
    } else {
        cout << "   - Treinador com mais medalhas: Nenhum registro." << endl;
    }

    // 6. RESUMO GERAL
    cout << "\n6. RESUMO GERAL DO SISTEMA:" << endl;
    cout << "   - Paises Cadastrados: " << paises.size() << endl;
    cout << "   - Modalidades Criadas: " << modalidade.size() << endl;
    cout << "   - Medalhas Distribuidas: " << medalhas.size() << endl;
    cout << "   - Treinadores Cadastrados: " << treinadores.size() << endl;
    cout << "==========================================" << endl;
}

#endif