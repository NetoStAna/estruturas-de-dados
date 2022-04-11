#include "03_fila_prioridades.h"

#include <iostream>
#include <cstddef>

using namespace std;

FilaPrioridades::FilaPrioridades()
{
    this->descritor.primeiro = NULL;
    this->descritor.tamanho_fila = 0;
}
FilaPrioridades::~FilaPrioridades()
{
    No *temp;
    No *primeiro = this->descritor.primeiro;

    while (primeiro != NULL)
    {
        temp = primeiro;
        primeiro = primeiro->proximo;

        delete temp;
    }
}

bool FilaPrioridades::esta_vazia()
{
    return (this->descritor.primeiro == NULL);
}
bool FilaPrioridades::esta_cheia()
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
int FilaPrioridades::tamanho_fila()
{
    return this->descritor.tamanho_fila;
}

bool FilaPrioridades::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    No *novo = new No;
    novo->individuo = individuo;

    if (this->descritor.primeiro == NULL)
    {
        this->descritor.primeiro = novo;
        novo->proximo = NULL;
    }
    else
    {
        No *anterior;
        No *atual = this->descritor.primeiro;

        while (atual != NULL && atual->individuo.get_idade() >= individuo.get_idade())
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == this->descritor.primeiro)
        {
            this->descritor.primeiro = novo;
            novo->proximo = atual;
        }
        else
        {
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
    }
    this->descritor.tamanho_fila++;

    return true;
}
Individuo FilaPrioridades::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
    No *removido = this->descritor.primeiro;
    Individuo individuo = removido->individuo;

    this->descritor.primeiro = removido->proximo;

    delete removido;
    this->descritor.tamanho_fila--;

    return individuo;
}
Individuo FilaPrioridades::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
    No *atual = this->descritor.primeiro;

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

void FilaPrioridades::imprimir()
{
    No *atual = this->descritor.primeiro;

    while (atual != NULL)
    {
        cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
        cout << "Nome: " << atual->individuo.get_nome() << endl;

        atual = atual->proximo;
    }
}
