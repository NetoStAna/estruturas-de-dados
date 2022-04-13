# Fila Estática

Armazena os dados de cada `Individuo` em forma de fila, ordenada por ordem de inserção, dentro de um `vetor` com tamanho alocado pelo usuário no tempo de execução.

A fila é inicializada com as variáveis `int`: primeiro, ultimo e capacidade_max, assim como um ponteiro `fila` para um vetor de objetos do tipo `Individuo`.

```cpp
class FilaEstatica
{
private:
    int primeiro, ultimo, capacidade_max;
    Individuo *fila;
```

 

## Construtor

A estrutura é construída inicializando-se as variáveis primeiro e último em `0`, assim como alocando-se o espaço de um `vetor` de objetos do tipo `Individuo` através de uma quantidade máxima de elementos definida pelo usuário e armazenada na variável capacidade_max.

```cpp
FilaEstatica::FilaEstatica(int capacidade_max)
{
    this->primeiro = 0;
    this->ultimo = 0;
    this->capacidade_max = capacidade_max;
    this->fila = new Individuo[this->capacidade_max];
}
```



## Destrutor

A estrutura é destruída ao liberar o espaço da memória onde o `vetor` foi alocado.

```cpp
FilaEstatica::~FilaEstatica()
{
    delete [] this->fila;
}
```



## Está Vazia

O método retorna o valor da igualdade entre o valor armazenado na variável `primeiro` e o valor armazenado na variável `ultimo`.

```cpp
bool FilaEstatica::esta_vazia()
{
    return (this->primeiro == this->ultimo);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está Cheia

O método retorna o valor da igualdade entre a diferença do valor armazenado na variável `ultimo` e o valor armazenado na variável `primeiro`, com o valor armazenado na variável `capacidade_max`.

```cpp
bool FilaEstatica::esta_cheia()
{
    return (this->ultimo - this->primeiro == this->capacidade_max);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Tamanho da Fila

O método retorna a diferença entre o valor armazenado na variável `ultimo` e o valor armazenado na variável `primeiro`.

```cpp
int FilaEstatica::tamanho_fila()
{
    return (this->ultimo - this->primeiro);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a fila está cheia. Em caso afirmativo, o método é encerrado e retorna o booleano `false`.

```cpp
bool FilaEstatica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
```

Caso contrário, o `Individuo` recebido como parâmetro é inserido na posição do `vetor` correspondente ao resto da divisão do valor armazenado na variável `ultimo` pelo valor armazenado na variável `capacidade_max`.

```cpp
	this->fila[this->ultimo % this->capacidade_max] = individuo;
```

Por fim, o valor armazenado na variável `ultimo` é incrementado em uma unidade e o método encerra, retornando o booleano `true`.

```cpp
	this->ultimo++;

	return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Remover

O método utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a fila está vazia. Em caso afirmativo o método é encerrado e retorna a variável generico.

```cpp
Individuo FilaEstatica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, o valor armazenado na variável `primeiro` é incrementado em uma unidade, e o `Individuo` armazenado na posição do `vetor` correspondente ao resto da divisão entre o valor armazenado na variável `primeiro` menos 1, pelo valor armazenado na variável `capacidade_max`.

```cpp
	this->primeiro++;

	return this->fila[(this->primeiro - 1) % this->capacidade_max];
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo FilaEstatica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
```

Caso contrário, o método utiliza um laço `for` que pode percorrer toda a fila.

```cpp
	for (int i = this->primeiro; i < this->ultimo; i++)
	{
```

A cada etapa do laço o `id` do `Individuo` armazenado na posição do vetor correspondente ao resto da divisão do valor de `i` pelo valor armazenado na variável `capacidade_max` é comparado ao `id` recebido como parâmetro. O primeiro elemento cujo `id` seja igual ao `id` recebido encerra o método e o `Individuo` dessa posição é retornado.

```cpp
        if (this->fila[i % this->capacidade_max].get_id() == id)
        {
            return this->fila[i % this->capacidade_max];
        }
```

Caso o laço complete toda a fila sem encontrar um `Individuo` cujo `id` seja igual ao recebido como parâmetro, a variável generico é retornada.

```cpp
	}

		return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Imprimir

O método utiliza um laço `for` que percorre toda a fila.

```cpp
void FilaEstatica::imprimir()
{
    for (int i = this->primeiro; i < this->ultimo; i++)
    {
```

A cada etapa do laço os dados do `Individuo` na posição do `vetor` correspondente ao resto da divisão do valor de `i` pelo valor armazenado na variável `capacidade_max`, são impressos no console.

```cpp
        cout << "\tIndivíduo id: " << this->fila[i % this->capacidade_max].get_id() << ", ";
        cout << "Nome: " << this->fila[i % this->capacidade_max].get_nome() << endl;
    }
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>

