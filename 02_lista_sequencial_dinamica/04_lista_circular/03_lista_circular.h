#include "01_individuo.h"

using namespace std;

struct No
{
    Individuo individuo;
    No *proximo;
};

struct Descritor
{
    No *inicio;
    No *final;
    int quantidade_itens;
};

class ListaCircular
{
private:
    Descritor descritor;
public:
    ListaCircular();
    ~ListaCircular();

    bool esta_cheia();
    bool esta_vazia();
    int quantidade_itens();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();
};
