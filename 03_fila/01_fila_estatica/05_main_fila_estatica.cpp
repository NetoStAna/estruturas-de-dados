#include "03_fila_estatica.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, id, idade, capacidade_max;
    float peso, altura;
    string nome;

    cout << "Algoritmo gerador de fila estática!\n";
    cout << "Digite a quantidade máxima de indivíduos a serem inseridos na fila!\n";
    cin >> capacidade_max;

    FilaEstatica fila_individuos(capacidade_max);

    do
    {
        cout << "Digite 1 para inserir um indivíduo na fila!\n";
        cout << "Digite 2 para remover um indivíduo da fila!\n";
        cout << "Digite 3 para buscar um indivíduo na fila!\n";
        cout << "Digite 4 para imprimir a fila de indivíduos!\n";
        cout << "Digite 5 para imprimir a quantidade de elementos válidos na fila!\n";
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

                bool resultado = fila_individuos.inserir(inserido);

                if (resultado)
                {
                    cout << "Indivíduo id: " << id << " inserido com sucesso!\n";
                }
            }
            else if (menu == 2)
            {
                Individuo removido = fila_individuos.remover();

                if (removido.get_id() != -1)
                {
                    cout << "Indivíduo id: " << removido.get_id() << " removido da lista!\n";
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

                Individuo buscado = fila_individuos.buscar(id);

                if (buscado.get_id() == -1)
                {
                    cout << "Indivíduo id: " << id << " não se encontra na fila!\n";
                }
                else
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
                cout << "Fila de indivíduos:\n";
                fila_individuos.imprimir();
            }
            else if(menu == 5)
            {
                cout << "A fila contém " << fila_individuos.tamanho_fila() << " indivíduos!\n";
            }
        }
    } while (menu != 6);

    cout << "Fim do algoritmo!\n";

    return 0;
}
