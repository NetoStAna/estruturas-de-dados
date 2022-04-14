#include "03_tabela_hash.h"

#include <iostream>
#include <math.h>

using namespace std;

int TabelaHash::funcao_hash(int id)
{
    int resultado, exp = 0, soma = 0;

    while (id != 0)
    {
        resultado = pow((id % 10), exp);
        soma += resultado;
        id /= 10;
        exp++;
    }

    return (soma % this->capacidade_max);
}

TabelaHash::TabelaHash(int capacidade_max)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->tabela = new No *[this->capacidade_max];
}
TabelaHash::~TabelaHash()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
        if (!this->tabela[i])
        {
            continue;
        }
        
        No *anterior;
        No *atual = this->tabela[i];
        while (atual != NULL)
        {
            anterior = atual;
            atual = atual->proximo;

            delete anterior;
        }
    }
    delete [] this->tabela;
}

bool TabelaHash::esta_vazia()
{
    return (this->quantidade_itens == 0);
}
bool TabelaHash::esta_cheia()
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
int TabelaHash::tamanho_tabela()
{
    return this->quantidade_itens;
}

bool TabelaHash::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a tabela está cheia!\n";

        return false;
    }
    int posicao = this->funcao_hash(individuo.get_id());
    No *novo = new No;

    novo->individuo = individuo;
    novo->proximo = NULL;

    if (!this->tabela[posicao])
    {
        this->tabela[posicao] = novo;
    }
    else
    {
        No *atual = this->tabela[posicao];

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    this->quantidade_itens++;

    return true;
}
Individuo TabelaHash::remover(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A tabela está vazia, nada a remover!\n";

        return generico;
    }
    int posicao = this->funcao_hash(id);

    if (!this->tabela[posicao])
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    No *anterior;
    No *atual = this->tabela[posicao];

    while (atual != NULL && atual->individuo.get_id() != id)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    Individuo individuo = atual->individuo;

    if (atual == this->tabela[posicao])
    {
        if (atual->proximo == NULL)
        {
            this->tabela[posicao] = new No;
        }
        else
        {
            this->tabela[posicao] = atual->proximo;
        }
    }
    else
    {
        anterior->proximo = atual->proximo;
    }
    delete atual;

    this->quantidade_itens--;

    return individuo;
}
Individuo TabelaHash::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A tabela está vazia, nada a buscar!\n";

        return generico;
    }
    int posicao = this->funcao_hash(id);

    if (!this->tabela[posicao])
    {
        cout << "O indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    No *atual = this->tabela[posicao];

    while (atual != NULL && atual->individuo.get_id() != id)
    {
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    
    return atual->individuo;
}

void TabelaHash::imprimir()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
        if (!this->tabela[i])
        {
            continue;
        }
        
        No *atual = this->tabela[i];

        while (atual != NULL)
        {
            cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
            cout << "Nome: " << atual->individuo.get_nome() << endl;

            atual = atual->proximo;
        }
    }
}
