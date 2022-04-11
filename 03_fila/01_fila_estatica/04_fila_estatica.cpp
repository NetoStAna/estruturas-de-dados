#include "03_fila_estatica.h"

#include <iostream>

using namespace std;

FilaEstatica::FilaEstatica(int capacidade_max)
{
    this->primeiro = 0;
    this->ultimo = 0;
    this->capacidade_max = capacidade_max;
    this->fila = new Individuo[this->capacidade_max];
}
FilaEstatica::~FilaEstatica()
{
    delete [] this->fila;
}

bool FilaEstatica::esta_vazia()
{
    return(this->primeiro == this->ultimo);
}
bool FilaEstatica::esta_cheia()
{
    return(this->ultimo - this->primeiro == this->capacidade_max);
}
int FilaEstatica::tamanho_fila()
{
    return(this->ultimo - this->primeiro);
}

bool FilaEstatica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    this->fila[this->ultimo % this->capacidade_max] = individuo;
    this->ultimo++;

    return true;
}
Individuo FilaEstatica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
    this->primeiro++;

    return this->fila[(this->primeiro - 1) % this->capacidade_max];
}
Individuo FilaEstatica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }

    for (int i = this->primeiro; i < this->ultimo; i++)
    {
        if (this->fila[i % this->capacidade_max].get_id() == id)
        {
            return this->fila[i % this->capacidade_max];
        }
    }

    return generico;
}

void FilaEstatica::imprimir()
{
    for (int i = this->primeiro; i < this->ultimo; i++)
    {
        cout << "\tIndivíduo id: " << this->fila[i % this->capacidade_max].get_id() << ", ";
        cout << "Nome: " << this->fila[i % this->capacidade_max].get_nome() << endl;
    }
}
