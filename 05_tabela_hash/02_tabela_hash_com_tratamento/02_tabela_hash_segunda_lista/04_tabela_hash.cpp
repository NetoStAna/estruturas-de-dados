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

    return (soma % this->capacidade_tabela);
}

TabelaHash::TabelaHash(int capacidade_tabela, int capacidade_colisoes)
{
    this->quantidade_itens = 0;
    this->ultima_colisao = 0;
    this->capacidade_tabela = capacidade_tabela;
    this->capacidade_colisoes = capacidade_colisoes;
    this->tabela = new Individuo[this->capacidade_tabela];
    this->colisoes = new Individuo[this->capacidade_colisoes];
}
TabelaHash::~TabelaHash()
{
    delete [] this->tabela;
    delete [] this->colisoes;
}

bool TabelaHash::esta_vazia(int id)
{
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() != -1)
    {
        return false;
    }
    
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() != -1)
        {
            return false;
        }
    }

    return true;
}
bool TabelaHash::esta_cheia(int id)
{
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == -1)
    {
        return false;
    }
    
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() == -1)
        {
            return false;
        }
    }
        
    return true;
}
int TabelaHash::tamanho_tabela()
{
    return this->quantidade_itens;
}

bool TabelaHash::inserir(Individuo individuo)
{
    if (this->esta_cheia(individuo.get_id()))
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois sua posição e a tabela de colisões está cheia!\n";

        return false;
    }
    int posicao = this->funcao_hash(individuo.get_id());

    if (this->tabela[posicao].get_id() == -1)
    {
        this->tabela[posicao] = individuo;
    }
    else
    {
        this->colisoes[this->ultima_colisao % this->capacidade_colisoes] = individuo;
        this->ultima_colisao++;
    }
    this->quantidade_itens++;

    return true;
}
Individuo TabelaHash::remover(int id)
{
    Individuo generico;

    if (this->esta_vazia(id))
    {
        cout << "A posição do id: " << id << " e a tabela de colisões estão vazias, nada a remover!\n";

        return generico;
    }
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == id)
    {
        Individuo individuo = this->tabela[posicao];
        this->tabela[posicao] = generico;
        this->quantidade_itens--;

        return individuo;
    }
    else
    {
        for (int i = 0; i < this->capacidade_colisoes; i++)
        {
            if (this->colisoes[i].get_id() == id)
            {
                Individuo individuo = this->colisoes[i];
                this->colisoes[i] = generico;
                this->quantidade_itens--;

                return individuo;
            }
        }
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}
Individuo TabelaHash::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia(id))
    {
        cout << "A posição do id: " << id << " e a tabela de colisões estão vazias, nada a buscar!\n";

        return generico;
    }
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == id)
    {
        return this->tabela[posicao];
    }
    else
    {
        for (int i = 0; i < this->capacidade_colisoes; i++)
        {
            if (this->colisoes[i].get_id() == id)
            {
                return this->colisoes[i];
            }
        }
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}

void TabelaHash::imprimir()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < this->capacidade_tabela; i++)
    {
        if (this->tabela[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->tabela[i].get_id() << ", ";
            cout << "Nome: " << this->tabela[i].get_nome() << endl;
        }
    }

    cout << "\n";

    cout << "Tabela de Colisões:\n";
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->colisoes[i].get_id() << ", ";
            cout << "Nome: " << this->colisoes[i].get_nome() << endl;
        }
    }
}
