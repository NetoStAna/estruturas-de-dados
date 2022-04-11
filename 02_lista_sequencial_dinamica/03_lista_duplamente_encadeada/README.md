# Lista Duplamente Encadeada

Armazena os dados de cada `Individuo` em uma lista de nós encadeados em duas direções, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

```cpp
struct No
{
    No *anterior;
    Individuo individuo;
    No *proximo;
};
```

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: quantidade_itens para armazenar a quantidade de nós no encadeamento.

```cpp
struct Descritor
{
    No *inicio;
    No *final;
    int quantidade_itens;
};

class ListaEncadeada
{
private:
    Descritor descritor;
```



## Construtor

A estrutura é construída apontando o ponteiro de início e de final do descritor para `NULL`, assim como inicializando a variável quantidade_itens do descritor em `0`.

```cpp
ListaEncadeada::ListaEncadeada()
{
    this->descritor.inicio = NULL;
    this->descritor.final = NULL;
    this->descritor.quantidade_itens = 0;
}
```



## Destrutor

A estrutura é destruída utilizando-se de um ponteiro para `No` auxiliar, denominado `anterior`, e um ponteiro para `No` apontado para o primeiro nó do encadeamento, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
ListaEncadeada::~ListaEncadeada()
{
    No *anterior;
    No *atual = this->descritor.inicio;
    
    while (atual != NULL)
    {
```

A cada etapa do loop, o ponteiro `anterior` recebe o ponteiro `atual`, o ponteiro `atual` passa para o próximo nó do encadeamento. e o nó do ponteiro `anterior` é liberado da memória. Ao fim do loop todos os nós do encadeamento são liberados, encerrando o método.

```cpp
        anterior = atual;
        atual = atual->proximo;

        delete anterior;
    }
}
```



## Está Vazia

O método retorna o valor da comparação entre a variável quantidade_itens do descritor e o valor `0`.

```cpp
bool ListaEncadeada::esta_vazia()
{
    return (this->descritor.quantidade_itens == 0);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está Cheia

O método utiliza um ponteiro para `No` denominado `temporario` e um operador `try` e `catch` para verificar se ainda há espaço em memória para realizar a criação de um novo `No`.

```cpp
bool ListaEncadeada::esta_cheia()
{
    No *temporario;

    try
    {
```

Caso a criação de um novo `No` seja realizada sem problemas, o `No` criado é liberado da memória e o método encerra retornando o booleano `false`.

```cpp
        temporario = new No;

        delete temporario;
        return false;
    }
```

Caso contrário, o método é encerrado retornando o booleano `true`.

```cpp
    catch(bad_alloc exception)
    {
        return true;
    }
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Quantidade de Itens

O método retorna o valor armazenado na variável quantidade_itens do descritor.

```cpp
int ListaEncadeada::quantidade_itens()
{
    return this->descritor.quantidade_itens;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a memória está cheia. Em caso afirmativo, o método é encerrado e retorna o booleano `false`.

```cpp
bool ListaEncadeada::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
```

Em caso negativo, um novo nó é inicializado, com o ponteiro do nó anterior apontado para o valo `NULL`, recebendo o `Individuo` do parâmetro e com o ponteiro do próximo nó apontado para o valor `NULL`.

```cpp
    else
    {
        No *novo = new No;
        novo->anterior = NULL;
        novo->individuo = individuo;
        novo->proximo = NULL;
```

Se o encadeamento estiver vazio, o ponteiro do início e do final do encadeamento é apontado para o novo nó.

```cpp

        if (this->descritor.inicio == NULL)
        {
            this->descritor.inicio = novo;
            this->descritor.final = novo;
        }
```

Caso contrário um ponteiro para `No` denominado `final` é apontado para o final do encadeamento, em seguida, o ponteiro `proximo` do ponteiro `final` é apontado para o novo `No`, inserindo-o desta forma no final da lista, o ponteiro `anterior` do novo `No` é apontado para o ponteiro `final` e o ponteiro `final` do descritor é apontado para o novo `No`.

```cpp
        else
        {
            No *final = this->descritor.final;

            final->proximo = novo;
            novo->anterior = final;
            this->descritor.final = novo;
        }
```

Por fim a variável quantidade_itens do descritor é incrementada em uma unidade e o método encerra retornando o booleano `true`.

```cpp
		this->descritor.quantidade_itens++;        

		return true;
    }
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Remover

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo ListaEncadeada::remover(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
```

Em caso negativo são utilizados um ponteiro para `No` utilizado de forma auxiliar, denominado `anterior` e um ponteiro para o início do encadeamento, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL` e o `id` do `Individuo` armazenado no ponteiro `atual` for diferente do `id` recebido como parâmetro.

```cpp
    else
    {
        No *anterior;
        No *atual = this->descritor.inicio;

        while (atual != NULL && atual->individuo.get_id() != id)
        {
```

A cada etapa do loop, o ponteiro `anterior` recebe o ponteiro `atual` e o ponteiro `atual` passa para o próximo nó do encadeamento. Ao final do loop é verificada a igualdade do ponteiro `atual` com o valor `NULL` e em caso afirmativo, o método é encerrado retornando a variável generico.

```cpp
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL)
        {
            cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

            return generico;
        }
```

Em caso negativo, um ponteiro para `No` denominado `proximo` é apontado para o ponteiro `proximo` do ponteiro `atual` e o `Individuo` armazenado no ponteiro `atual` é salvo em uma variável `Individuo`: individuo. Em seguida, se o ponteiro `atual` for igual ao ponteiro `inicio` do descritor, o ponteiro `inicio` é apontado para o ponteiro `proximo` do ponteiro `atual` e o ponteiro `anterior` do ponteiro `proximo` é apontado para o valor `NULL`.

```cpp
        No *proximo = atual->proximo;
		Individuo individuo = atual->individuo;

        if (atual == this->descritor.inicio)
        {
            this->descritor.inicio = atual->proximo;
            proximo->anterior = NULL;
        }
```

Caso o ponteiro `atual` for igual ao ponteiro `final` do descritor, o ponteiro `final` é apontado para o ponteiro `anterior` e o ponteiro `proximo` do ponteiro `anterior` é apontado para o valor `NULL`.

```cpp
		else if (atual == this->descritor.final)
        {
            this->descritor.final = anterior;
            anterior->proximo = NULL;
        }
```

Caso contrário, o ponteiro `proximo` do ponteiro `anterior` é apontado para o ponteiro `proximo` e o ponteiro `anterior` do ponteiro `proximo` é apontado para o ponteiro `anterior`.

```cpp
        else
        {
            anterior->proximo = proximo;
            proximo->anterior = anterior;
        }
```

Por fim, o ponteiro `atual` é liberado da memória, a variável quantidade_itens do descritor é decrementada em uma unidade e o método encerra, retornando a variável individuo.

```cpp
        delete atual;
		this->descritor.quantidade_itens--;

        return individuo;
    }
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo ListaEncadeada::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
```

Em caso negativo são utilizados um ponteiro para `No` apontado para o início do encadeamento, denominado `atual` e um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL` e o `id` do `Individuo` armazenado no ponteiro `atual` for diferente do `id` recebido como parâmetro.

```cpp
    else
    {
        No *atual = this->descritor.inicio;

        while (atual != NULL && atual->individuo.get_id() != id)
        {
```

A cada etapa do loop, o ponteiro  `atual` passa para o próximo nó do encadeamento. Ao final do loop é verificada a igualdade do ponteiro `atual` com o valor `NULL` e em caso afirmativo, o método é encerrado retornando a variável generico.

```cpp
            atual = atual->proximo;
        }

        if (atual == NULL)
        {
            cout << "Indivíduo id: " << id << " não se encontra na lista!\n";

            return generico;
        }
```

Caso contrário, o método é encerrado, retornando o `Individuo` armazenado no ponteiro `atual`.

```cpp
        else
        {
            return atual->individuo;
        }
    }
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Imprimir

O método utiliza um ponteiro para o início do encadeamento denominado `atual` e um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
void ListaEncadeada::imprimir()
{
    No *atual = this->descritor.inicio;

    while (atual != NULL)
    {
```

A cada etapa do loop as informações do `Individuo` armazenado no ponteiro `atual` são impressas no console e o ponteiro `atual` recebe o próximo nó do encadeamento.

```cpp
        cout << "Indivíduo id: " << atual->individuo.get_id() << endl;
        cout << "\tNome: " << atual->individuo.get_nome() << endl;
        cout << "\tIdade: " << atual->individuo.get_idade() << " anos\n";
        cout << "\tPeso: " << atual->individuo.get_peso() << " kg\n";
        cout << "\tAltura: " << atual->individuo.get_altura() << " m\n";

        atual = atual->proximo;
    }
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>

