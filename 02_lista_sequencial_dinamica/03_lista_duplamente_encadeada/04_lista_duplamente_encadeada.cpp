#include "03_lista_duplamente_encadeada.h"

#include <iostream>
#include <cstddef>

using namespace std;

ListaEncadeada::ListaEncadeada()
{
    this->descritor.inicio = NULL;
    this->descritor.final = NULL;
    this->descritor.quantidade_itens = 0;
}
ListaEncadeada::~ListaEncadeada()
{
    No *anterior;
    No *atual = this->descritor.inicio;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->proximo;

        delete anterior;
    }
}

bool ListaEncadeada::esta_cheia()
{
    No *temporario;

    try
    {
        temporario = new No;

        delete temporario;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
bool ListaEncadeada::esta_vazia()
{
    return (this->descritor.quantidade_itens == 0);
}
int ListaEncadeada::quantidade_itens()
{
    return this->descritor.quantidade_itens;
}

bool ListaEncadeada::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    else
    {
        No *novo = new No;
        novo->anterior = NULL;
        novo->individuo = individuo;
        novo->proximo = NULL;

        if (this->descritor.inicio == NULL)
        {
            this->descritor.inicio = novo;
            this->descritor.final = novo;
        }
        else
        {
            No *final = this->descritor.final;

            final->proximo = novo;
            novo->anterior = final;
            this->descritor.final = novo;
        }
        this->descritor.quantidade_itens++;

        return true;
    }
}
Individuo ListaEncadeada::remover(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
    else
    {
        No *anterior;
        No *atual = this->descritor.inicio;

        while (atual != NULL && atual->individuo.get_id() != id)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL)
        {
            cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

            return generico;
        }
        No *proximo = atual->proximo;
        Individuo individuo = atual->individuo;

        if (atual == this->descritor.inicio)
        {
            this->descritor.inicio = atual->proximo;
            proximo->anterior = NULL;
        }
        else if (atual == this->descritor.final)
        {
            this->descritor.final = anterior;
            anterior->proximo = NULL;
        }
        else
        {
            anterior->proximo = proximo;
            proximo->anterior = anterior;
        }
        delete atual;
        this->descritor.quantidade_itens--;
                
        return individuo;
    }
}
Individuo ListaEncadeada::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
    else
    {
        No *atual = this->descritor.inicio;

        while (atual != NULL && atual->individuo.get_id() != id)
        {
            atual = atual->proximo;
        }

        if (atual == NULL)
        {
            cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

            return generico;
        }
        else
        {
            return atual->individuo;
        }
    }
}

void ListaEncadeada::imprimir()
{
    No *atual = this->descritor.inicio;

    while (atual != NULL)
    {
        cout << "Indivíduo id: " << atual->individuo.get_id() << endl;
        cout << "\tNome: " << atual->individuo.get_nome() << endl;
        cout << "\tIdade: " << atual->individuo.get_idade() << " anos\n";
        cout << "\tPeso: " << atual->individuo.get_peso() << " kg\n";
        cout << "\tAltura: " << atual->individuo.get_altura() << " m\n";

        atual = atual->proximo;
    }
}
