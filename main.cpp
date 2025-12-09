#include "funcao.h"
#include <limits>

int main()
{
    SistemaOlimpico sistema;
    sistema.carregarDados();
    int opcao = -1;

    if(sistema.buscarAtleta("Joao Silva") == nullptr) 
        cout<<"Atleta Joao Silva nao encontrado apos carregar dados."<<endl;
    else 
        cout<<"Atleta Joao Silva encontrado apos carregar dados."<<endl;
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
             << "9. Salvar dados e sair" << endl;
        cout << "Digite 0 para sair: ";
        cin >> opcao;


        switch (opcao)
        {
        case 1:
        {
            cout << "[Cadastrar pais]" << endl;
            string nome;
            string codigo;
            cout << "Digite o nome do pais: ";
            cin >> nome;
            cout << "Digite o codigo do pais: ";
            cin >> codigo;
            sistema.cadastrarPais(nome, codigo);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        case 2:
        {
            string nome, genero, codPais;
            int anoNascimento;

            cout << "--- Cadastrar Atleta ---" << endl;
            
            // CORREÇÃO: Limpar o buffer antes de ler a linha inteira
            cout << "Digite o nome do Atleta: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o 'enter' anterior
            getline(cin, nome); // Lê "Joao Silva" inteiro

            cout << "Digite o genero do Atleta: ";
            cin >> genero;

            cout << "Digite o ano de nascimento do Atleta: ";
            cin >> anoNascimento;

            cout << "Digite o codigo do pais do Atleta: ";
            cin >> codPais;

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
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << " Digite o nome da modalidade: " << endl;
            cin >> nome;
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << " Digite o evento da modalidade: " << endl;
            cin >> evento;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            sistema.criarModalidade(codigo, nome, evento);
            break;
        }
        case 4:
        {
            cout << "[Criar medalha]" << endl;
            string tipo, codModalidade;
            int ano;
            cout << " Digite o tipo da medalha: (ouro, prata ou bronze)" << endl;
            cin >> tipo;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << " Digite o ano em que a medalha foi dada: "<< endl;
             //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> ano;
            // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << " Digite o codigo da modalidade que foi concida a medalha: " << endl;
            cin >> codModalidade;
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            sistema.criarMedalha(tipo, ano, codModalidade);
            break;
        }
        case 5:
        {
            cout << "--- Premiar Atleta com medalha ---" << endl;
            string nomeAtleta, tipo, codModalidade;
            int ano;

            // CORREÇÃO: Ler nome composto
            cout << "Digite o NOME do atleta: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer
            getline(cin, nomeAtleta); // Lê "Joao Silva"

            cout << "Digite o tipo de medalha (ouro, prata, bronze): ";
            cin >> tipo;
            
            cout << "Digite o ano: ";
            cin >> ano;
            
            cout << "Digite o codigo da modalidade: ";
            cin >> codModalidade;

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
                 << "Digite o codigo da modalidade" << endl;
            cin >> cod;
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            sistema.listarAtletasPorModalidade(cod);
            break;
        }
        case 8:
        {
            // PONTO EXTRA: Chamada da função de estatísticas
            sistema.gerarRelatoriosEstatisticos();
            
            // Pausa para o usuário ler antes de voltar ao menu
            cout << "\nPressione ENTER para voltar ao menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer
            cin.get(); // Espera um enter
            break;
        }

        case 9:
        {
            sistema.salvarDados();
            break;
        }
        case 0:
        {
            cout << "Saindo do programa..." << endl;
            break;
        }
        default:
        {
            cout << "Opcao invalida! Digite um numero entre 0 e 9. Tente novamente." << endl;
        }
        }

    } while (opcao != 0 && opcao != 9);
    return 0;
}