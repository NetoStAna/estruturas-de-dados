#include "01_individuo.h"

using namespace std;

class PilhaEstatica
{
private:
    int quantidade_itens, capacidade_max;
    Individuo *pilha;
public:
    PilhaEstatica(int capacidade_max);
    ~PilhaEstatica();

    bool esta_vazia();
    bool esta_cheia();
    int tamanho_pilha();

    bool inserir(Individuo individuo);
    Individuo remover();
    Individuo buscar(int id);

    void imprimir();
};
