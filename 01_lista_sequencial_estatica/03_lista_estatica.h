#include "01_individuo.h"

using namespace std;

class Lista
{
private:
    int quantidade_max;
    Individuo *lista;
public:
    Lista(int quantidade_max);
    ~Lista();

    bool esta_vazia();
    bool esta_cheia();
    int quantidade_itens();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
