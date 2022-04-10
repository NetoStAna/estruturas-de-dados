#include "03_lista_encadeada.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, id, idade;
    float peso, altura;
    string nome;

    cout << "Algoritmo gerador de lista dinâmica encadeada!\n";

    ListaEncadeada lista_individuos;

    do
    {
        cout << "Digite 1 para inserir um indivíduo na lista!\n";
        cout << "Digite 2 para remover um indivíduo da lista!\n";
        cout << "Digite 3 para buscar um indivíduo na lista!\n";
        cout << "Digite 4 para imprimir a lista de indivíduos!\n";
        cout << "Digite 5 para imprimir a quantidade de elementos válidos na lista!\n";
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

                cout << "Digite o nome do individuo: ";
                cin >> nome;

                cout << "Digite a idade do indivíduo: ";
                cin >> idade;

                cout << "Digite o peso do indivíduo: ";
                cin >> peso;

                cout << "Digite a altura do indivíduo: ";
                cin >> altura;

                Individuo inserido(id, idade, peso, altura, nome);

                bool resultado = lista_individuos.inserir(inserido);

                if (resultado)
                {
                    cout << "Indivíduo id: " << id << " inserido com sucesso!\n";
                }
            }
            else if (menu == 2)
            {
                cout << "Digite o id do indivíduo a ser removido: ";
                cin >> id;

                Individuo removido = lista_individuos.remover(id);

                if (removido.get_id() != -1)
                {
                    cout << "Indivíduo id: " << id << " removido da lista!\n";
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

                Individuo buscado = lista_individuos.buscar(id);

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
                cout << "Lista de indivíduos:\n";
                lista_individuos.imprimir();
            }
            else if(menu == 5)
            {
                cout << "A lista contém " << lista_individuos.quantidade_itens() << " indivíduos!\n";
            }
        }
    } while (menu != 6);

    cout << "Fim do algoritmo!\n";

    return 0;
}
