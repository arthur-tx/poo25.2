#include "funcao.h"
#include <limits>

int main()
{
    SistemaOlimpico sistema;
    sistema.carregarDados();
    int opcao = -1;
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
        cout << "Menu ainda nao implementado. Digite 0 para sair: ";
        cin >> opcao;


        switch (opcao)
        {
        case 1:
        {
            cout << "Cadastrar pais" << endl;
            string nome;
            string codigo;
            cout << "Digite o nome e o codigo do pais: ";
            cin >> nome;
            cin >> codigo;
            sistema.cadastrarPais(nome, codigo);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        case 2:
        {
            string nome, genero, codPais;
            int anoNascimento;
            cout << " Cadastrar atleta" << endl;
            cout << "Digite o nome do Atleta" << endl;
            cin >> nome;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Digite o genero do Atleta" << endl;
            cin >> genero;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Digite o ano de nascimento do Atleta" << endl;
            cin >> anoNascimento;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Digite o codigo do pais do Atleta" << endl;
            cin >> codPais;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            sistema.cadastrarAtleta(nome, genero, anoNascimento, codPais);
            break;
        }
        case 3:
        {
            cout << "Criar modalidade" << endl;
            int evento;
            string nome, codigo;
            cout << " Digite o codigo da modalidade: " << endl;
            cin >> codigo;
            cout << " Digite o nome da modalidade: " << endl;
            cin >> nome;
            cout << " Digite o evento da modalidade: " << endl;
            cin >> evento;
            sistema.criarModalidade(codigo, nome, evento);
            break;
        }
        case 4:
        {
            cout << "Criar medalha" << endl;
            string tipo, codModalidade;
            int ano;
            cout << " Digite o tipo da medalha: (ouro, prata ou bronze)" << endl;
            cin >> tipo;
            cout << " Digite o ano em que a medalha foi dada: " << endl;
            cin >> ano;
            cout << " Digite o codigo da modalidade que foi concida a medalha: " << endl;
            cin >> codModalidade;
            sistema.criarMedalha(tipo, ano, codModalidade);
            break;
        }
        case 5:
        {
            cout << " Premiar Atleta com medalha" << endl;
            string cpf, tipo, codModalidade;
            int ano;
            cout << "Digite o CPF do atleta, o tipo de medalha, o ano em questao e o codigo da modalidade" << endl;
            cin >> cpf;
            cin >> tipo;
            cin >> ano;
            cin >> codModalidade;
            sistema.premiarAtletaMedalha(cpf, tipo, ano, codModalidade);
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
            cout << "Listar atletas de uma modalidade" << endl
                 << "Digite o codigo da modalidade" << endl;
            cin >> cod;
            sistema.listarAtletasPorModalidade(cod);
            break;
        }
        case 8:
        {
            cout << "Gerar relatorios e estatistica (ainda nao implementado)" << endl;
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