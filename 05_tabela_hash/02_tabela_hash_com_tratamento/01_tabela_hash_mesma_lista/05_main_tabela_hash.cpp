#include "03_tabela_hash.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, id, idade, capacidade_max, tamanho_total;
    float peso, altura;
    string nome;

    cout << "Algoritmo gerador de tabela hash (com tratamento de colisão na mesma lista)!\n";


    do
    {
        cout << "Digite o tamanho total da tabela: ";
        cin >> tamanho_total;

        cout << "Digite a quantidade máxima de indivíduos a serem inseridos na tabela: ";
        cin >> capacidade_max;

        if (capacidade_max > tamanho_total)
        {
            cout << "A quantidade máxima de indivíduos não pode exceder o tamanho total da tabela!\n";
        }
    } while (capacidade_max > tamanho_total);

    TabelaHash tabela_individuos(capacidade_max, tamanho_total);

    do
    {
        cout << "Digite 1 para inserir um indivíduo na tabela!\n";
        cout << "Digite 2 para remover um indivíduo da tabela!\n";
        cout << "Digite 3 para buscar um indivíduo na tabela!\n";
        cout << "Digite 4 para imprimir a tabela de indivíduos!\n";
        cout << "Digite 5 para imprimir a quantidade de elementos válidos na tabela!\n";
        cout << "Digite 6 para encerrar o algoritmo!\n";
        cin >> menu;

        if (menu < 1 || menu > 6)
        {
            cout << "Opção de menu não atribuída!\n";
            cout << "Digite uma opção válida!\n";
        }
        else
        {
            if (menu == 1)
            {
                cout << "Digite o id do indivíduo: ";
                cin >> id;

                cout << "Digite o nome do indivíduo: ";
                cin >> nome;

                cout << "Digite a idade do indivíduo: ";
                cin >> idade;

                cout << "Digite o peso do indivíduo: ";
                cin >> peso;

                cout << "Digite a altura do indivíduo: ";
                cin >> altura;

                Individuo inserido(id, idade, peso, altura, nome);

                bool resultado = tabela_individuos.inserir(inserido);

                if (resultado)
                {
                    cout << "Indivíduo id: " << id << " inserido com sucesso!\n";
                }
            }
            else if (menu == 2)
            {
                cout << "Digite o id do indivíduo a ser removido: ";
                cin >> id;

                Individuo removido = tabela_individuos.remover(id);

                if (removido.get_id() != -1)
                {
                    cout << "Indivíduo id: " << id << " removido da tabela!\n";
                    cout << "\tNome: " << removido.get_nome() << endl;
                    cout << "\tIdade: " << removido.get_idade() << " anos\n";
                    cout << "\tPeso: " << removido.get_peso() << " kg\n";
                    cout << "\tAltura: " << removido.get_altura() << " m\n";
                }
            }
            else if (menu == 3)
            {
                cout << "Digite o id do indivíduo a ser buscado: ";
                cin >> id;

                Individuo buscado = tabela_individuos.buscar(id);

                if (buscado.get_id() != -1)
                {
                    cout << "Indivíduo id: " << id << endl;
                    cout << "\tNome: " << buscado.get_nome() << endl;
                    cout << "\tIdade: " << buscado.get_idade() << " anos\n";
                    cout << "\tPeso: " << buscado.get_peso() << " kg\n";
                    cout << "\tAltura: " << buscado.get_altura() << " m\n";
                }
            }
            else if (menu == 4)
            {
                cout << "Tabela de indivíduos:\n";
                tabela_individuos.imprimir();
            }
            else if (menu == 5)
            {
                cout << "A tabela contém " << tabela_individuos.tamanho_tabela() << " indivíduos!\n";
            }
        }
    } while (menu != 6);
    
    cout << "Fim do algoritmo!\n";

    return 0;
}
