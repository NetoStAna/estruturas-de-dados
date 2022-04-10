#include "01_individuo.h"

using namespace std;

struct No
{
    Individuo individuo;
    No *proximo;
};

class ListaEncadeada
{
private:
    No *inicio;
public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool esta_cheia();
    bool esta_vazia();
    int quantidade_itens();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
