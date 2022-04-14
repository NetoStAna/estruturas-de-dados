#include "01_individuo.h"

using namespace std;

Individuo::Individuo()
{
    this->id = -1;
    this->idade = 0;
    this->peso = 0;
    this->altura = 0;
    this->nome = "";
}
Individuo::Individuo(int id, int idade, float peso, float altura, string nome)
{
    this->id = id;
    this->idade = idade;
    this->peso = peso;
    this->altura = altura;
    this->nome = nome;
}

int Individuo::get_id()
{
    return this->id;
}

int Individuo::get_idade()
{
    return this->idade;
}
void Individuo::set_idade(int idade)
{
    this->idade = idade;
}

float Individuo::get_peso()
{
    return this->peso;
}
void Individuo::set_peso(float peso)
{
    this->peso = peso;
}

float Individuo::get_altura()
{
    return this->altura;
}
void Individuo::set_altura(float altura)
{
    this->altura = altura;
}

string Individuo::get_nome()
{
    return this->nome;
}
