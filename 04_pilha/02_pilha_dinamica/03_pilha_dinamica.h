#include "01_individuo.h"

using namespace std;

struct No
{
    Individuo individuo;
    No *proximo;
};

struct Descritor
{
    No *topo;
    int tamanho_pilha;
};

class PilhaDinamica
{
private:
    Descritor descritor;
public:
    PilhaDinamica();
    ~PilhaDinamica();

    bool esta_cheia();
    bool esta_vazia();
    int tamanho_pilha();

    bool inserir(Individuo individuo);
    Individuo remover();
    Individuo buscar(int id);

    void imprimir();
};
