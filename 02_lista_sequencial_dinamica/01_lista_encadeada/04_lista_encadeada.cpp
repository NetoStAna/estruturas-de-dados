#include "03_lista_encadeada.h"

#include <iostream>
#include <cstddef>

using namespace std;

ListaEncadeada::ListaEncadeada()
{
    this->inicio = NULL;
}
ListaEncadeada::~ListaEncadeada()
{
    No *anterior;
    No *atual = this->inicio;

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
    return (this->inicio == NULL);
}
int ListaEncadeada::quantidade_itens()
{
    int cont = 0;
    No* atual = this->inicio;

    while (atual != NULL)
    {
        atual = atual->proximo;
        cont++;
    }
    return cont;
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
        novo->individuo = individuo;
        novo->proximo = NULL;

        if (this->inicio == NULL)
        {
            this->inicio = novo;
        }
        else
        {
            No *final = this->inicio;

            while (final->proximo != NULL)
            {
                final = final->proximo;
            }
            final->proximo = novo;
        }
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
        No *atual = this->inicio;

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
        Individuo individuo = atual->individuo;

        if (atual == this->inicio)
        {
            this->inicio = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
        delete atual;
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
        No *atual = this->inicio;

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
    No *atual = this->inicio;

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
