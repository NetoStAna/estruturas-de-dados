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
    this->tabela = new Individuo[this->capacidade_max];
}
TabelaHash::~TabelaHash()
{
    delete [] this->tabela;
}

bool TabelaHash::esta_vazia()
{
    return (this->quantidade_itens == 0);
}
bool TabelaHash::esta_cheia()
{
    return (this->quantidade_itens == this->capacidade_max);
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

    if (this->tabela[posicao].get_id() == -1)
    {
        this->quantidade_itens++;
    }
    this->tabela[posicao] = individuo;

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
    Individuo individuo = this->tabela[posicao];

    if (individuo.get_id() != id)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    this->tabela[posicao] = generico;
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
    Individuo individuo = this->tabela[posicao];

    if (individuo.get_id() != id)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
    
    return individuo;
}

void TabelaHash::imprimir()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
        if (this->tabela[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->tabela[i].get_id() << ", ";
            cout << "Nome: " << this->tabela[i].get_nome() << endl;
        }
    }
}
