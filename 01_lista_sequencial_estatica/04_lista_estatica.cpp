#include "03_lista_estatica.h"

#include <iostream>

using namespace std;

Lista::Lista(int quantidade_max)
{
    this->quantidade_max = quantidade_max;
    this->lista = new Individuo[this->quantidade_max];
}
Lista::~Lista()
{
    delete [] this->lista;
}

bool Lista::esta_vazia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            return false;
        }
    }
    return true;
}
bool Lista::esta_cheia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            return false;
        }
    }
    return true;
}
int Lista::quantidade_itens()
{
    int count = 0;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            count++;
        }
    }
    return count;
}

bool Lista::inserir(Individuo individuo)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            this->lista[i] = individuo;

            return true;
        }
    }
    return false;
}
Individuo Lista::remover(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            Individuo removido;

            removido = this->lista[i];
            this->lista[i] = generico;

            return removido;
        }
    }
    return generico;
}
Individuo Lista::buscar(int id)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
    }
    Individuo generico;

    return generico;
}

void Lista::imprimir()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            cout << "Indivíduo id: " << this->lista[i].get_id() << endl;
            cout << "\tNome: " << this->lista[i].get_nome() << endl;
            cout << "\tIdade: " << this->lista[i].get_idade() << " anos\n";
            cout << "\tPeso: " << this->lista[i].get_peso() << " kg\n";
            cout << "\tAltura: " << this->lista[i].get_altura() << " m\n";
        }
    }
}
