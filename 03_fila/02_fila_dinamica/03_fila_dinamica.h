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
    No *ultimo;
    int tamanho_fila;
};

class FilaDinamica
{
private:
    Descritor descritor;
public:
    FilaDinamica();
    ~FilaDinamica();

    bool esta_cheia();
    bool esta_vazia();
    int tamanho_fila();

    bool inserir(Individuo individuo);
    Individuo remover();
    Individuo buscar(int id);

    void imprimir();
};
