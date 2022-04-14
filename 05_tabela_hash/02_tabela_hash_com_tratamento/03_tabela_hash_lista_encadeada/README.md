# Colisões em Lista Encadeada

Insere as colisões em uma lista de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

```cpp
struct No
{
    Individuo individuo;
    No *proximo;
};
```

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela e `int`: capacidade_max, para indicar a quantidade máxima de posições no `vetor`, assim como um ponteiro `tabela` para um `vetor` de ponteiros para `No`. 

```cpp
class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, capacidade_max;
    No **tabela;
```



## Construtor

A estrutura é construída inicializando-se a variável `quantidade_itens` em `0`, assim como alocando-se um `vetor` de ponteiros para `No` com uma quantidade máxima de itens, definida pelo usuário.

```cpp
TabelaHash::TabelaHash(int capacidade_max)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->tabela = new No *[this->capacidade_max];
}
```



## Destrutor

A estrutura é destruída utilizando-se um laço `for` que percorre toda a tabela.

```cpp
TabelaHash::~TabelaHash()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
```

A cada etapa do laço é verificado se a posição `i` da tabela está vazia, em caso afirmativo, o laço passa para a próxima etapa através do comando `continue`.

```cpp
        if (!this->tabela[i])
        {
            continue;
        }
```

Caso contrário, é utilizado um ponteiro para `No` auxiliar, denominado `anterior`, e um ponteiro para `No` apontado para a posição `i` da tabela, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
        
        No *anterior;
        No *atual = this->tabela[i];
        while (atual != NULL)
        {
```

A cada etapa do loop, o ponteiro `anterior` recebe o ponteiro `atual`, o ponteiro `atual` passa para o próximo nó do encadeamento. e o nó do ponteiro `anterior` é liberado da memória. Ao fim do loop todos os nós do encadeamento da posição `i` da tabela são liberados da memória.

```cpp
            anterior = atual;
            atual = atual->proximo;

            delete anterior;
```

Por fim, o `vetor` tabela é liberado da memória, encerrando o método.

```cpp
        }
    }
    delete [] this->tabela;
}
```



## Está Vazia

O método retorna o valor da comparação entre a variável `quantidade_itens` e o valor `0`.

```cpp
bool TabelaHash::esta_vazia()
{
    return (this->quantidade_itens == 0);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está Cheia

O método utiliza um ponteiro para `No` denominado `temp` e um operador `try` e `catch` para verificar se ainda há espaço em memória para realizar a criação de um novo `No`.

```cpp
bool TabelaHash::esta_cheia()
{
    No *temp;

    try
    {
```

Caso a criação de um novo `No` seja realizada sem problemas, o `No` criado é liberado da memória e o método encerra retornando o booleano `false`.

```cpp
        temp = new No;

        delete temp;
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



## Tamanho da Tabela

O método retorna o valor armazenado na variável `quantidade_itens`.

```cpp
int TabelaHash::tamanho_tabela()
{
    return this->quantidade_itens;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a tabela está cheia. Em caso afirmativo, o método é encerrado e retorna o booleano `false`.

```cpp
bool TabelaHash::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a tabela está cheia!\n";

        return false;
    }
```

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao e um novo nó é inicializado, recebendo o `Individuo` do parâmetro e com o ponteiro do próximo nó apontado para o valor `NULL`. Em seguida, é verificado se a posição correspondente da tabela está vazia, em caso afirmativo, o novo `No` é inserido na posição correspondente.

```cpp
    int posicao = this->funcao_hash(individuo.get_id());
    No *novo = new No;

    novo->individuo = individuo;
    novo->proximo = NULL;

    if (!this->tabela[posicao])
    {
        this->tabela[posicao] = novo;
    }
```

Caso contrário um ponteiro para `No` denominado `atual` é apontado para a posição correspondente da tabela e utiliza-se um loop `while` que segue enquanto o ponteiro `proximo` do ponteiro `final` for diferente de `NULL`.

```cpp
    else
    {
        No *atual = this->tabela[posicao];

        while (atual->proximo != NULL)
        {
```

A cada etapa do loop, o ponteiro `atual` recebe o próximo nó do encadeamento, desta forma ao fim do loop o ponteiro `atual` receberá o último nó do encadeamento. Em seguida, o ponteiro `proximo` do ponteiro `atual` é apontado para o novo `No`, inserindo-o desta forma no final da lista.

```cpp
            atual = atual->proximo;
        }
        atual->proximo = novo;
```

Por fim, a variável `quantidade_itens` é incrementada em uma unidade e o método é encerrado, retornando o booleano `true`.

```cpp
    }
    this->quantidade_itens++;

    return true;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(n)</sub> _(Lista Encadeada da Posição Correspondente)_



## Remover

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`:  generico, inicializada pelo construtor padrão e verifica se a tabela está  vazia. Em caso afirmativo o método é encerrado e retorna a variável  generico.

```cpp
Individuo TabelaHash::remover(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A tabela está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao. Em seguida, é verificado se a posição correspondente da tabela está vazia, em caso afirmativo, o método é encerrado, retornando a variável `generico`.

```cpp
    int posicao = this->funcao_hash(id);

    if (!this->tabela[posicao])
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Em caso negativo são utilizados um ponteiro para `No` utilizado de forma auxiliar, denominado `anterior` e um ponteiro para a posição correspondente da tabela, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL` e o `id` do `Individuo` armazenado no ponteiro `atual` for diferente do `id` recebido como parâmetro.

```cpp
    No *anterior;
    No *atual = this->tabela[posicao];

    while (atual != NULL && atual->individuo.get_id() != id)
    {
```

A cada etapa do loop, o ponteiro `anterior` recebe o ponteiro `atual` e o ponteiro `atual` passa para o próximo nó do encadeamento. Ao final do loop é verificada a igualdade do ponteiro `atual` com o valor `NULL` e em caso afirmativo, o método é encerrado retornando a variável `generico`.

```cpp
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Em caso negativo, o `Individuo` armazenado no ponteiro `atual` é salvo em uma variável `Individuo`: individuo. Em seguida, se o ponteiro `atual` for igual à posição correspondente da tabela, é verificada a igualdade entre o ponteiro `proximo` do ponteiro `atual` e o valor `NULL`, em caso afirmativo a posição correspondente da tabela recebe um novo `No`.

```cpp
    Individuo individuo = atual->individuo;

    if (atual == this->tabela[posicao])
    {
        if (atual->proximo == NULL)
        {
            this->tabela[posicao] = new No;
        }
```

Caso contrário, a posição correspondente da tabela recebe o ponteiro `proximo` do ponteiro `atual`.

```cpp
        else
        {
            this->tabela[posicao] = atual->proximo;
        }
```

Se  o ponteiro `atual` for diferente da posição correspondente da tabela, o ponteiro `proximo` do ponteiro `anterior` recebe o ponteiro `proximo` do ponteiro `atual`.

```cpp
    }
    else
    {
        anterior->proximo = atual->proximo;
    }
```

Por fim, o ponteiro `atual` é liberado da memória, a variável `quantidade_itens` é decrementada em uma unidade e o método é encerrado, retornando a variável `individuo`.

```cpp
    delete atual;

    this->quantidade_itens--;

    return individuo;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(n)</sub> _(Lista Encadeada da Posição Correspondente)_



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`:  generico, inicializada pelo construtor padrão e verifica se a tabela está  vazia. Em caso afirmativo o método é encerrado e retorna a variável  generico.

```cpp
Individuo TabelaHash::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A tabela está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao. Em seguida, é verificado se a posição correspondente da tabela está vazia, em caso afirmativo, o método é encerrado, retornando a variável `generico`.

```cpp
    int posicao = this->funcao_hash(id);

    if (!this->tabela[posicao])
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Em caso negativo é utilizado um ponteiro para `No` apontado para a posição correspondente da tabela, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL` e o `id` do `Individuo` armazenado no ponteiro `atual` for diferente do `id` recebido como parâmetro.

```cpp
    No *atual = this->tabela[posicao];

    while (atual != NULL && atual->individuo.get_id() != id)
    {
```

A cada etapa do loop, o ponteiro `atual` passa para o próximo nó do encadeamento. Ao final do loop é verificada a igualdade do ponteiro `atual` com o valor `NULL` e em caso afirmativo, o método é encerrado retornando a variável `generico`.

```cpp
        atual = atual->proximo;
    }
    
    if (atual == NULL)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Em caso negativo, o método é encerrado, retornando a variável `individuo`.

```cpp
    
    return atual->individuo;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(n)</sub> _(Lista Encadeada da Posição Correspondente)_



## Imprimir

O método utiliza um laço `for` que percorre toda a tabela.

```cpp
void TabelaHash::imprimir()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
```

A cada etapa do laço é verificado se a posição `i` da tabela está vazia, em caso afirmativo, o laço passa para a próxima etapa através do comando `continue`.

```cpp
        if (!this->tabela[i])
        {
            continue;
        }
```

Caso contrário, é utilizado um ponteiro para `No` apontado para a posição `i` da tabela, denominado `atual`, assim como um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
        
        No *atual = this->tabela[i];

        while (atual != NULL)
        {
```

A cada etapa do loop as informações do `Individuo` armazenado no ponteiro `atual`são impressas no console e o ponteiro `atual` passa para o próximo nó do encadeamento.

```cpp
            cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
            cout << "Nome: " << atual->individuo.get_nome() << endl;

            atual = atual->proximo;
        }
    }
}
```

> Melhor Caso: O<sub>(n)</sub> _(Cada Item de Cada Lista Encadeada da Tabela)_
>
> Pior Caso: O<sub>(n)</sub> _(Cada Item de Cada Lista Encadeada da Tabela)_
