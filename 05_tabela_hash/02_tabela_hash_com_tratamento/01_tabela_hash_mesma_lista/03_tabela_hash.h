#include "01_individuo.h"

using namespace std;

class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, capacidade_max, tamanho_total;
    Individuo *tabela;
public:
    TabelaHash(int capacidade_max, int tamanho_total);
    ~TabelaHash();

    bool esta_vazia();
    bool esta_cheia();
    int tamanho_tabela();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
