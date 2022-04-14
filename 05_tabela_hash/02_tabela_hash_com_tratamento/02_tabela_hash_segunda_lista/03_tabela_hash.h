#include "01_individuo.h"

using namespace std;

class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, ultima_colisao, capacidade_tabela, capacidade_colisoes;
    Individuo *tabela, *colisoes;
public:
    TabelaHash(int capacidade_tabela, int capacidade_colisoes);
    ~TabelaHash();

    bool esta_vazia(int id);
    bool esta_cheia(int id);
    int tamanho_tabela();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
