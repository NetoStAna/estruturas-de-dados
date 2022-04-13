#include "03_pilha_estatica.h"

#include <iostream>

using namespace std;

PilhaEstatica::PilhaEstatica(int capacidade_max)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->pilha = new Individuo[this->capacidade_max];
}
PilhaEstatica::~PilhaEstatica()
{
    delete [] this->pilha;
}

bool PilhaEstatica::esta_vazia()
{
    return(this->quantidade_itens == 0);
}
bool PilhaEstatica::esta_cheia()
{
    return(this->quantidade_itens == this->capacidade_max);
}
int PilhaEstatica::tamanho_pilha()
{
    return(this->quantidade_itens);
}

bool PilhaEstatica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    this->pilha[this->quantidade_itens] = individuo;
    this->quantidade_itens++;

    return true;
}
Individuo PilhaEstatica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
    this->quantidade_itens--;

    return this->pilha[this->quantidade_itens];
}
Individuo PilhaEstatica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }

    for (int i = this->quantidade_itens; i > 0; i--)
    {
        if (this->pilha[i - 1].get_id() == id)
        {
            return this->pilha[i - 1];
        }
    }

    return generico;
}

void PilhaEstatica::imprimir()
{
    for (int i = this->quantidade_itens; i > 0; i--)
    {
        cout << "\tIndivíduo id: " << this->pilha[i - 1].get_id() << ", ";
        cout << "Nome: " << this->pilha[i - 1].get_nome() << endl;
    }
}
