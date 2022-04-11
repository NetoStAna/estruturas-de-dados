#include "01_individuo.h"

using namespace std;

struct No
{
    Individuo individuo;
    No *proximo;
};

struct Descritor
{
    No *primeiro;
    int tamanho_fila;
};

class FilaPrioridades
{
private:
    Descritor descritor;
public:
    FilaPrioridades();
    ~FilaPrioridades();

    bool esta_cheia();
    bool esta_vazia();
    int tamanho_fila();

    bool inserir(Individuo individuo);
    Individuo remover();
    Individuo buscar(int id);

    void imprimir();
};
