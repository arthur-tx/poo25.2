#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Medalha;
class Modalidade;
class Pais;

class Pessoa
{
protected:
    string nome;
    string genero;
    int anoNascimento;
    Pais *pais;
    vector<Modalidade *> modalidades;

public:
    Pessoa(const string &nome, const string &genero, int anoNascimento, Pais *pais);
    virtual ~Pessoa() = default;

    // getters e setters
    string getNome() const;
    void setNome(const string &nome);
    string getGenero() const;
    void setGenero(const string &genero);
    int getAnoNascimento() const;
    void setAnoNascimento(int anoNascimento);
    Pais *getPais() const;
    void setPais(Pais *novoPais);

    const vector<Modalidade *> &getModalidades() const;
    void adicionarModalidade(Modalidade *modalidade);

    virtual void imprimirInformacoes() const = 0;
    virtual string getTipo() const = 0;
};

#endif