# Lista Sequencial Estática

 Armazena os dados de cada `Individuo` em um `vetor` com tamanho alocado pelo usuário no tempo de execução.



## Construtor

A estrutura é construída alocando-se o espaço de um `vetor` de objetos do tipo `Individuo` através de uma quantidade máxima de elementos definida pelo usuário.

```cpp
Lista::Lista(int quantidade_max)
{
    this->quantidade_max = quantidade_max;
    this->lista = new Individuo[this->quantidade_max];
}
```



## Destrutor

A estrutura é destruída ao liberar o espaço da memória onde o `vetor` foi alocado.

```cpp
Lista::~Lista()
{
    delete [] this->lista;
}
```



## Está Vazia

O método utiliza um laço `for` que pode percorrer todo o `vetor` da lista.

```cpp
bool Lista::esta_vazia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` do construtor padrão, `-1`. O primeiro elemento cujo `id` seja diferente do construtor padrão encerra o método e retorna o booleano `false`.

```cpp
        if (this->lista[i].get_id() != -1)
        {
            return false;
        }
```

Caso o laço complete todo o `vetor` sem encontrar um `Individuo` diferente do construtor padrão, o método é encerrado e retorna o booleano `true`.

```cpp
    }
    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Está Cheia

O método utiliza um laço `for` que pode percorrer todo o `vetor` da lista.

```cpp
bool Lista::esta_cheia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` do construtor padrão, `-1`. O primeiro elemento cujo `id` seja igual ao construtor padrão encerra o método e retorna o booleano `false`.

```cpp
        if (this->lista[i].get_id() == -1)
        {
            return false;
        }

```

Caso o laço complete todo o `vetor` sem encontrar um `Individuo` igual ao construtor padrão, o método é encerrado e retorna o booleano `true`.

```cpp
    }
    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Quantidade de Itens

O método utiliza uma variável `int`: count, iniciada em `0`; e um laço `for` que percorre todo o `vetor` da lista.

```cpp
int Lista::quantidade_itens()
{
    int count = 0;

    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` do construtor padrão, `-1`. A cada elemento cujo `id` seja diferente do construtor padrão, a variável count é incrementada em uma unidade.

```cpp
        if (this->lista[i].get_id() != -1)
        {
            count++;
        }
```

Ao final do laço o método encerra retornando o valor da variável count.

```cpp
    }
    return count;
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e utiliza um laço `for` que pode percorrer todo o `vetor` da lista.

```cpp
bool Lista::inserir(Individuo individuo)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` do construtor padrão, `-1`. A posição do primeiro elemento encontrado cujo `id` seja igual ao construtor padrão é utilizada para armazenar o `Individuo` a ser inserido, o método é encerrado e retorna o booleano `true`.

```cpp
        if (this->lista[i].get_id() == -1)
        {
            this->lista[i] = individuo;

            return true;
        }
```

Caso o laço complete todo o `vetor` sem encontrar um `Individuo` igual ao construtor padrão, o método é encerrado e retorna o booleano `false`.

```cpp
    }
    return false;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Remover

O método recebe uma variável `int`: id como parâmetro e utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão, assim como um laço `for` que pode percorrer todo o `vetor` da lista.

```cpp
Individuo Lista::remover(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` recebido. O elemento cujo `id` seja igual ao `id` recebido é salvo em uma variável `Individuo`: removido.

```cpp
        if (this->lista[i].get_id() == id)
        {
            Individuo removido;

            removido = this->lista[i];
```

A posição do `Individuo` removido no `vetor` é preenchida com o `Individuo` generico e o método é encerrado retornando o `Individuo` removido.

```cpp
            this->lista[i] = generico;

            return removido;
        }
```

Caso o laço complete todo o `vetor` sem encontrar um `Individuo` com `id` igual ao recebido como parâmetro, o método é encerrado e retorna o `Individuo` generico.

```cpp
    }
    return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro e utiliza um laço `for` que pode percorrer todo o `vetor` da lista.

```cpp
Individuo Lista::buscar(int id)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
    }
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` recebido. O `Individuo` cujo `id` seja igual ao `id` recebido é retornado e o método é encerrado.

```cpp
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
```

Caso o laço complete todo o `vetor` sem encontrar um `Individuo` com `id` igual ao recebido como parâmetro, uma variável `Individuo`: generico é inicializada pelo construtor padrão, o método é encerrado, e a mesma é retornada.

```cpp
    Individuo generico;

    return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Imprimir

O método utiliza um laço `for` que percorre todo o `vetor` da lista.

```cpp
void Lista::imprimir()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` de cada `Individuo` na posição `i` do `vetor` é comparado ao `id` do construtor padrão, `-1`. Para cada `Individuo` cujo `id` seja diferente do construtor padrão, suas informações são impressas no console.

```cpp
        if (this->lista[i].get_id() != -1)
        {
            cout << "Individuo id: " << this->lista[i].get_id() << endl;
            cout << "\tNome: " << this->lista[i].get_nome() << endl;
            cout << "\tIdade: " << this->lista[i].get_idade() << " anos\n";
            cout << "\tPeso: " << this->lista[i].get_peso() << " kg\n";
            cout << "\tAltura: " << this->lista[i].get_altura() << " m\n";
        }
    }
}
```

Após percorrer todo o `vetor` o método é encerrado.

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>

