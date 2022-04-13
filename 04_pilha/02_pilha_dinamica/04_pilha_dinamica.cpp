#include "03_pilha_dinamica.h"

#include <iostream>
#include <cstddef>

using namespace std;

PilhaDinamica::PilhaDinamica()
{
    this->descritor.topo = NULL;
    this->descritor.tamanho_pilha = 0;
}
PilhaDinamica::~PilhaDinamica()
{
    No *temp;

    while (this->descritor.topo != NULL)
    {
        temp = this->descritor.topo;
        this->descritor.topo = this->descritor.topo->proximo;

        delete temp;
    }
}

bool PilhaDinamica::esta_vazia()
{
    return (this->descritor.topo == NULL);
}
bool PilhaDinamica::esta_cheia()
{
    No *temp;

    try
    {
        temp = new No;

        delete temp;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
int PilhaDinamica::tamanho_pilha()
{
    return this->descritor.tamanho_pilha;
}

bool PilhaDinamica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    No *novo = new No;
    novo->individuo = individuo;
    novo->proximo = this->descritor.topo;
    this->descritor.topo = novo;
    this->descritor.tamanho_pilha++;

    return true;
}
Individuo PilhaDinamica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
    No *removido = this->descritor.topo;
    Individuo individuo = removido->individuo;

    this->descritor.topo = removido->proximo;

    delete removido;
    this->descritor.tamanho_pilha--;

    return individuo;
}
Individuo PilhaDinamica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
    No *atual = this->descritor.topo;

    while (atual != NULL && atual->individuo.get_id() != id)
    {
        atual = atual->proximo;
    }
    
    if (atual == NULL)
    {
        cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

        return generico;
    }

    return atual->individuo;
}

void PilhaDinamica::imprimir()
{
    No *atual = this->descritor.topo;

    while (atual != NULL)
    {
        cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
        cout << "Nome: " << atual->individuo.get_nome() << endl;

        atual = atual->proximo;
    }
}
