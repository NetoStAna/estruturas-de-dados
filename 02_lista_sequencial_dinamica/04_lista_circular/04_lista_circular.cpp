#include "03_lista_circular.h"

#include <iostream>
#include <cstddef>

using namespace std;

ListaCircular::ListaCircular()
{
    this->descritor.inicio = NULL;
    this->descritor.final = NULL;
    this->descritor.quantidade_itens = 0;
}
ListaCircular::~ListaCircular()
{
    No *anterior;
    No *atual = this->descritor.inicio;

    while (atual->proximo != this->descritor.inicio)
    {
        anterior = atual;
        atual = atual->proximo;

        delete anterior;
    }
    delete atual;
}

bool ListaCircular::esta_cheia()
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
bool ListaCircular::esta_vazia()
{
    return (this->descritor.quantidade_itens == 0);
}
int ListaCircular::quantidade_itens()
{
    return this->descritor.quantidade_itens;
}

bool ListaCircular::inserir(Individuo individuo)
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

        if (this->descritor.inicio == NULL)
        {
            this->descritor.inicio = novo;
            this->descritor.final = novo;
        }
        else
        {
            No *final = this->descritor.final;

            final->proximo = novo;
            this->descritor.final = novo;
        }
        novo->proximo = this->descritor.inicio;
        this->descritor.quantidade_itens++;

        return true;
    }
}
Individuo ListaCircular::remover(int id)
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

        do
        {
            if (atual->individuo.get_id() != id)
            {
                anterior = atual;
                atual = atual->proximo;
            }
            else
            {
                Individuo individuo = atual->individuo;

                if (atual == this->descritor.inicio)
                {
                    this->descritor.inicio = atual->proximo;
                    this->descritor.final->proximo = atual->proximo;
                }
                else if (atual == this->descritor.final)
                {
                    this->descritor.final = anterior;
                    anterior->proximo = this->descritor.inicio;
                }
                else
                {
                    anterior->proximo = atual->proximo;
                }
                delete atual;
                this->descritor.quantidade_itens--;

                return individuo;
            }
        } while (atual != this->descritor.inicio);
        cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

        return generico;
    }
}
Individuo ListaCircular::buscar(int id)
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

        do
        {
            if (atual->individuo.get_id() != id)
            {
                atual = atual->proximo;
            }
            else
            {
                return atual->individuo;
            }
        } while (atual != this->descritor.inicio);
        cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

        return generico;
    }
}

void ListaCircular::imprimir()
{
    No *atual = this->descritor.inicio;

    do
    {
        cout << "Indivíduo id: " << atual->individuo.get_id() << endl;
        cout << "\tNome: " << atual->individuo.get_nome() << endl;
        cout << "\tIdade: " << atual->individuo.get_idade() << " anos\n";
        cout << "\tPeso: " << atual->individuo.get_peso() << " kg\n";
        cout << "\tAltura: " << atual->individuo.get_altura() << " m\n";

        atual = atual->proximo;
    } while (atual != this->descritor.inicio);
}
