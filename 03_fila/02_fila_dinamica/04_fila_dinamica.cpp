#include "03_fila_dinamica.h"

#include <iostream>
#include <cstddef>

using namespace std;

FilaDinamica::FilaDinamica()
{
    this->descritor.primeiro = NULL;
    this->descritor.ultimo = NULL;
    this->descritor.tamanho_fila = 0;
}
FilaDinamica::~FilaDinamica()
{
    No *temp;
    No *primeiro = this->descritor.primeiro;

    while (primeiro != NULL)
    {
        temp = primeiro;
        primeiro = primeiro->proximo;

        delete temp;
    }
    this->descritor.ultimo = NULL;
}

bool FilaDinamica::esta_vazia()
{
    return (this->descritor.primeiro == NULL);
}
bool FilaDinamica::esta_cheia()
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
int FilaDinamica::tamanho_fila()
{
    return this->descritor.tamanho_fila;
}

bool FilaDinamica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
    No *novo = new No;
    novo->individuo = individuo;
    novo->proximo = NULL;

    if (this->descritor.primeiro == NULL)
    {
        this->descritor.primeiro = novo;
        this->descritor.ultimo = novo;
    }
    else
    {
        No *ultimo = this->descritor.ultimo;

        ultimo->proximo = novo;
        this->descritor.ultimo = novo;
    }
    this->descritor.tamanho_fila++;

    return true;
}
Individuo FilaDinamica::remover()
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
Individuo FilaDinamica::buscar(int id)
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

void FilaDinamica::imprimir()
{
    No *atual = this->descritor.primeiro;

    while (atual != NULL)
    {
        cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
        cout << "Nome: " << atual->individuo.get_nome() << endl;

        atual = atual->proximo;
    }
}
