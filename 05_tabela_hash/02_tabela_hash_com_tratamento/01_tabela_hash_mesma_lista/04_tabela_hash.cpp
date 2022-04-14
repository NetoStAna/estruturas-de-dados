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

    return (soma % this->tamanho_total);
}

TabelaHash::TabelaHash(int capacidade_max, int tamanho_total)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->tamanho_total = tamanho_total;
    this->tabela = new Individuo[this->tamanho_total];
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

    while (this->tabela[posicao].get_id() != -1 && this->tabela[posicao].get_id() != -2)
    {
        posicao = (posicao + 1) % this->tamanho_total;
    }
    this->tabela[posicao] = individuo;
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

    while (this->tabela[posicao].get_id() != -1)
    {
        if (this->tabela[posicao].get_id() == id)
        {
            Individuo individuo = this->tabela[posicao];

            this->tabela[posicao] = Individuo(-2, 0, 0, 0, "");
            this->quantidade_itens--;

            return individuo;
        }
        posicao = (posicao + 1) % this->tamanho_total;
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
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

    while (this->tabela[posicao].get_id() != -1)
    {
        if (this->tabela[posicao].get_id() == id)
        {
            return this->tabela[posicao];
        }
        posicao = (posicao + 1) % this->tamanho_total;
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}

void TabelaHash::imprimir()
{
    for (int i = 0; i < this->tamanho_total; i++)
    {
        if (this->tabela[i].get_id() > -1)
        {
            cout << "\tIndivíduo id: " << this->tabela[i].get_id() << ", ";
            cout << "Nome: " << this->tabela[i].get_nome() << endl;
        }
    }
}
