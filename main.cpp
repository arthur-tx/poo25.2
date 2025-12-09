#include "funcao.h"
#include <limits>

int main()
{
    SistemaOlimpico sistema;
    sistema.carregarDados();
    int opcao = -1;

    // Teste inicial apenas para feedback visual
 /* if(sistema.buscarAtleta("Joao Silva") == nullptr) 
        cout << "Atleta Joao Silva nao encontrado apos carregar dados (Teste inicial)." << endl;
    else 
        cout << "Atleta Joao Silva encontrado apos carregar dados." << endl;
*/
    do
    {
        cout << "\n========= MENU PRINCIPAL =======" << endl;
        cout << "1. Cadastrar pais" << endl
             << "2. Cadastrar atleta" << endl
             << "3. Criar modalidade" << endl
             << "4. Criar medalha" << endl
             << "5. Premiar atleta com medalha" << endl
             << "6. Exibir quadro de medalhas" << endl
             << "7. Listar atletas de uma modalidade" << endl
             << "8. Gerar relatorios e estatistica" << endl
             << "9. Salvar dados Parcial" << endl
             <<"10. Salvar e sair" << endl;
        cout << "Digite 0 para sair: ";
        
        // Tratamento de entrada para o menu (evita loop infinito se digitar letra)
        if (!(cin >> opcao)) {
            cout << "Entrada invalida! Digite um numero." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = -1;
            continue;
        }

        switch (opcao)
        {
        case 1:
        {
            cout << "[Cadastrar pais]" << endl;
            string nome;
            string codigo;
            
            cout << "Digite o nome do pais: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer antes do getline
            getline(cin, nome);
            
            cout << "Digite o codigo do pais (ex: BRA): ";
            cin >> codigo;
            codigo = paraMaiusculo(codigo); // [NOVO] Padroniza

            sistema.cadastrarPais(nome, codigo);
            break;
        }
        case 2:
        {
            string nome, genero, codPais;
            int anoNascimento;

            cout << "--- Cadastrar Atleta ---" << endl;
            
            cout << "Digite o nome do Atleta: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer
            getline(cin, nome); 

            cout << "Digite o genero do Atleta (M/F): ";
            cin >> genero;
            genero = paraMaiusculo(genero); // [NOVO] Padroniza

            cout << "Digite o ano de nascimento do Atleta: ";
            cin >> anoNascimento;

            cout << "Digite o codigo do pais do Atleta: ";
            cin >> codPais;
            codPais = paraMaiusculo(codPais); // [NOVO] Padroniza

            sistema.cadastrarAtleta(nome, genero, anoNascimento, codPais);
            break;
        }
        case 3:
        {
            cout << "[Criar modalidade]" << endl;
            int evento;
            string nome, codigo;
            
            cout << " Digite o codigo da modalidade: " << endl;
            cin >> codigo;
            codigo = paraMaiusculo(codigo); // [NOVO] Padroniza
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa buffer
            
            cout << " Digite o nome da modalidade: " << endl;
            getline(cin, nome); // Usa getline para nomes compostos (ex: Volei de Praia)
            
            cout << " Digite o evento da modalidade: " << endl;
            cin >> evento;
            
            sistema.criarModalidade(codigo, nome, evento);
            break;
        }
        case 4:
        {
            cout << "[Criar medalha]" << endl;
            string tipo, codModalidade;
            int ano;
            
            cout << " Digite o tipo da medalha (Ouro, Prata ou Bronze): " << endl;
            cin >> tipo;
            tipo = paraMaiusculo(tipo); // [NOVO] Padroniza
            
            cout << " Digite o ano em que a medalha foi dada: "<< endl;
            cin >> ano;
            
            cout << " Digite o codigo da modalidade: " << endl;
            cin >> codModalidade;
            codModalidade = paraMaiusculo(codModalidade); // [NOVO] Padroniza
            
            sistema.criarMedalha(tipo, ano, codModalidade);
            break;
        }
        case 5:
        {
            cout << "--- Premiar Atleta com medalha ---" << endl;
            string nomeAtleta, tipo, codModalidade;
            int ano;

            cout << "Digite o NOME do atleta: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer
            getline(cin, nomeAtleta); 
           // nomeAtleta = paraMaiusculo(nomeAtleta); // [NOVO] Padroniza

            cout << "Digite o tipo de medalha (ouro, prata, bronze): ";
            cin >> tipo;
            tipo = paraMaiusculo(tipo); // [NOVO] Padroniza
            
            cout << "Digite o ano: ";
            cin >> ano;
            
            cout << "Digite o codigo da modalidade: ";
            cin >> codModalidade;
            codModalidade = paraMaiusculo(codModalidade); // [NOVO] Padroniza

            sistema.premiarAtletaMedalha(nomeAtleta, tipo, ano, codModalidade);
            break;
        }
        case 6:
        {
            sistema.exibirQuadroMedalhas();
            break;
        }
        case 7:
        {
            string cod;
            cout << "[Listar atletas de uma modalidade]" << endl
                 << "Digite o codigo da modalidade: " << endl;
            cin >> cod;
            cod = paraMaiusculo(cod); // [NOVO] Padroniza busca
            
            sistema.listarAtletasPorModalidade(cod);
            break;
        }
        case 8:
        {
            // PONTO EXTRA
            sistema.gerarRelatoriosEstatisticos();
            
            cout << "\nPressione ENTER para voltar ao menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get(); 
            break;
        }

        case 9:
        {
            sistema.salvarDados();
            break;
        }
        case 10:
        {
            sistema.salvarDados();
            cout << "Saindo do programa..." << endl;
            opcao = 0; // Força saída do loop
            break;
        }
        case 0:
        {
            cout << "Saindo do programa..." << endl;
            break;
        }
        default:
        {
            cout << "Opcao invalida! Digite um numero entre 0 e 9." << endl;
        }
        }

    } while (opcao != 0 );
    return 0;
}