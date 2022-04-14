#include <iostream>

using namespace std;

class Individuo
{
private:
    int id, idade;
    float peso, altura;
    string nome;
public:
    Individuo();
    Individuo(int id, int idade, float peso, float altura, string nome);

    int get_id();

    int get_idade();
    void set_idade(int idade);

    float get_peso();
    void set_peso(float peso);

    float get_altura();
    void set_altura(float altura);

    string get_nome();
};
