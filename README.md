# Sistema de Gerenciamento Olímpico 🥇

Este é um sistema desenvolvido em C++ para o gerenciamento de dados de uma olimpíada. O software permite o cadastro e controle de países, atletas, treinadores, modalidades e medalhas, além de oferecer funcionalidades de relatórios e persistência de dados.

## 📋 Funcionalidades

O sistema conta com um menu interativo via terminal que permite:

* **Cadastros:** Inserir novos Países, Atletas, Modalidades e Medalhas.
* **Gestão:** Premiar atletas com medalhas (Ouro, Prata, Bronze).
* **Relatórios:**
    * Exibir quadro geral de medalhas (ranking por país).
    * Listar atletas por modalidade.
* **Persistência:** Carregar e salvar todos os dados automaticamente em arquivo de texto (`dados_olimpicos.txt`).

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (Padrão C++17)
* **Estruturas de Dados:** `vector`, ponteiros inteligentes (`unique_ptr`).
* **Armazenamento:** Arquivo de texto (.txt) formatado.

## 📂 Estrutura de Arquivos

* `main.cpp`: Arquivo principal contendo o menu e o loop do programa.
* `funcao.h`: Implementação das funções principais e lógica do sistema.
* `SistemaOlimpico.h`: Definição da classe gerenciadora.
* `pessoa.h`, `atleta.h`, `treinador.h`: Classes de hierarquia de pessoas.
* `pais.h`, `modalidade.h`, `medalha.h`: Entidades do sistema.
* `dados_olimpicos.txt`: Banco de dados simples para salvar o estado do sistema.

## 🚀 Como Compilar e Executar

Certifique-se de ter o compilador `g++` instalado.

### 1. Compilação
Abra o terminal na pasta do projeto e execute o seguinte comando:

```bash
g++ -std=c++17 -o exe main.cpp
./exe