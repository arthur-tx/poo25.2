#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <string>
#include <iostream>

using namespace std;

class Modalidade {
public:
    string codigo;
    string nome;
    int evento;
    
    Modalidade(const string& codigo, const string& nome, int evento);
    string getCodigo() const;
    string getNome() const;
    int getEvento() const;
   
    void setCodigo(const string& novoCodigo);
    void setNome(const string& novoNome);
    void setEvento( int novoEvento);
    
    void imprimirInformacoes() const;
};

#endif