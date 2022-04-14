#include "01_individuo.h"

#include <cstddef>

using namespace std;

struct No
{
    Individuo individuo;
    No *proximo;
};

class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, capacidade_max;
    No **tabela;
public:
    TabelaHash(int capacidade_max);
    ~TabelaHash();

    bool esta_vazia();
    bool esta_cheia();
    int tamanho_tabela();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
