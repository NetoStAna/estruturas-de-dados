#include "01_individuo.h"

using namespace std;

class FilaEstatica
{
private:
    int primeiro, ultimo, capacidade_max;
    Individuo *fila;
public:
    FilaEstatica(int capacidade_max);
    ~FilaEstatica();

    bool esta_vazia();
    bool esta_cheia();
    int tamanho_fila();

    bool inserir(Individuo individuo);
    Individuo remover();
    Individuo buscar(int id);

    void imprimir();
};
