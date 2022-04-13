# Pilha Estática

Armazena os dados de cada `Individuo` em forma de pilha, dentro de um `vetor` com tamanho alocado pelo usuário no tempo de execução.

A pilha é inicializada com as variáveis `int`: quantidade_itens e capacidade_max, assim como um ponteiro `pilha` para um vetor de objetos do tipo `Individuo`.

```cpp
class PilhaEstatica
{
private:
    int quantidade_itens, capacidade_max;
    Individuo *pilha;
```

 

## Construtor

A estrutura é construída inicializando-se a variável quantidade_itens em `0`, assim como alocando-se o espaço de um `vetor` de objetos do tipo `Individuo` através de uma quantidade máxima de elementos definida pelo usuário e armazenada na variável capacidade_max.

```cpp
PilhaEstatica::PilhaEstatica(int capacidade_max)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->pilha = new Individuo[this->capacidade_max];
}
```



## Destrutor

A estrutura é destruída ao liberar o espaço da memória onde o `vetor` foi alocado.

```cpp
PilhaEstatica::~PilhaEstatica()
{
    delete [] this->pilha;
}
```



## Está Vazia

O método retorna o valor da igualdade entre o valor armazenado na variável `quantidade_itens` e o valor `0`.

```cpp
bool PilhaEstatica::esta_vazia()
{
    return (this->quantidade_itens == 0);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está Cheia

O método retorna o valor da igualdade entre o valor armazenado na variável `quantidade_itens` e o valor armazenado na variável `capacidade_max`.

```cpp
bool PilhaEstatica::esta_cheia()
{
    return(this->quantidade_itens == this->capacidade_max);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Tamanho da Pilha

O método retorna o valor armazenado na variável `quantidade_itens`.

```cpp
int PilhaEstatica::tamanho_pilha()
{
    return(this->quantidade_itens);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a pilha está cheia. Em caso afirmativo, o método é encerrado e retorna o booleano `false`.

```cpp
bool PilhaEstatica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
```

Caso contrário, o `Individuo` recebido como parâmetro é inserido na posição do `vetor` correspondente ao valor da variável `quantidade_itens`, esta é incrementada em uma unidade e o método é encerrado, retornando o booleano `true`.

```cpp
    this->pilha[this->quantidade_itens] = individuo;
    this->quantidade_itens++;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Remover

O método utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a fila está vazia. Em caso afirmativo o método é encerrado e retorna a variável generico.

```cpp
Individuo PilhaEstatica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, o valor armazenado na variável `quantidade_itens` é decrementado em uma unidade, e o `Individuo` armazenado na posição do `vetor` correspondente ao novo valor desta é retornado, encerrando o método.

```cpp
    this->quantidade_itens--;

    return this->pilha[this->quantidade_itens];
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo PilhaEstatica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
```

Caso contrário, o método utiliza um laço `for` que pode percorrer toda a pilha.

```cpp
	for (int i = this->quantidade_itens; i > 0; i--)
	{
```

A cada etapa do laço o `id` do `Individuo` armazenado na posição do vetor correspondente ao valor de `i` menos `1` é comparado ao `id` recebido como parâmetro. O primeiro elemento cujo `id` seja igual ao `id` recebido encerra o método e o `Individuo` dessa posição é retornado.

```cpp
        if (this->pilha[i - 1].get_id() == id)
        {
            return this->pilha[i - 1];
        }
```

Caso o laço complete toda a pilha sem encontrar um `Individuo` cujo `id` seja igual ao recebido como parâmetro, a variável generico é retornada.

```cpp
	}

	return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Imprimir

O método utiliza um laço `for` que percorre toda a pilha.

```cpp
void PilhaEstatica::imprimir()
{
    for (int i = this->quantidade_itens; i > 0; i--)
    {
```

A cada etapa do laço os dados do `Individuo` na posição do `vetor` correspondente ao valor de `i` menos `1` são impressos no console.

```cpp
        cout << "\tIndivíduo id: " << this->pilha[i - 1].get_id() << ", ";
        cout << "Nome: " << this->pilha[i - 1].get_nome() << endl;
    }
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>

