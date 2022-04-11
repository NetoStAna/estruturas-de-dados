# Fila Dinâmica

Armazena os dados de cada `Individuo` em forma de fila, ordenada por ordem de inserção, através de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

```cpp
struct No
{
    Individuo individuo;
    No *proximo;
};
```

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: tamanho_fila para armazenar a quantidade de nós no encadeamento.

 ```cpp
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
 ```



## Construtor

A estrutura é construída apontando os ponteiros `primeiro`e `ultimo` do descritor para o valor `NULL`, assim como inicializando a variável `tamanho_fila` do descritor em `0`.

```cpp
FilaDinamica::FilaDinamica()
{
    this->descritor.primeiro = NULL;
    this->descritor.ultimo = NULL;
    this->descritor.tamanho_fila = 0;
}
```



## Destrutor

A estrutura é destruída utilizando-se um ponteiro para `No` auxiliar, denominado `temp`, e um ponteiro para `No`, apontado para o início da fila, denominado `primeiro`, assim como um loop `while` que segue enquanto o ponteiro `primeiro` for diferente de `NULL`.

```cpp
FilaDinamica::~FilaDinamica()
{
    No *temp;
    No *primeiro = this->descritor.primeiro;

    while (primeiro != NULL)
    {
```

A cada etapa do loop, o ponteiro `temp` recebe o ponteiro `primeiro`, o ponteiro `primeiro` passa para o próximo nó do encadeamento. e o nó do ponteiro `temp` é liberado da memória. Ao fim do loop todos os nós do encadeamento são liberados e o ponteiro `ultimo` do descritor é apontado para o valor `NULL`, encerrando o método.

```cpp
        temp = primeiro;
        primeiro = primeiro->proximo;

        delete temp;
    }
    this->descritor.ultimo = NULL;
}
```



## Está Vazia

O método retorna o valor da comparação entre o ponteiro `primeiro` do descritor e o valor `NULL`.

```cpp
bool FilaDinamica::esta_vazia()
{
    return (this->descritor.primeiro == NULL);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está cheia

O método utiliza um ponteiro para `No` denominado `temporario` e um operador `try` e `catch` para verificar se ainda há espaço em memória para realizar a criação de um novo `No`.

```cpp
bool FilaDinamica::esta_cheia()
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



## Tamanho da Fila

O método retorna o valor armazenado na variável `tamanho_fila` do descritor.

```cpp
int FilaDinamica::tamanho_fila()
{
    return this->descritor.tamanho_fila;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a fila está cheia. Em caso afirmativo, o método é encerrado, retornando o booleano `false`.

```cpp
bool FilaDinamica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
```

Caso contrário, um novo nó é inicializado, recebendo o `Individuo` do parâmetro e com o ponteiro do próximo nó apontado para o valor `NULL`.

```cpp
    No *novo = new No;
    novo->individuo = individuo;
    novo->proximo = NULL;
```

Se o encadeamento estiver vazio, o ponteiro `primeiro` e `ultimo` do descritor são apontados para o novo `No`.

```cpp
	
	if (this->descritor.primeiro == NULL)
    {
        this->descritor.primeiro = novo;
        this->descirotr.ultimo = novo;
    }
```

Caso contrário um ponteiro para `No` denominado `ultimo` é apontado para o final do encadeamento, em seguida, o ponteiro `proximo` do ponteiro `ultimo` é apontado para o novo `No`, inserindo-o desta forma no final da lista e o ponteiro `ultimo` do descritor é apontado para o novo `No`.

```cpp
    else
    {
        No *ultimo = this->descritor.ultimo;

        ultimo->proximo = novo;
        this->descritor.ultimo = novo;
    }
```

Por fim a variável `tamanho_fila` do descritor é incrementada em uma unidade e o método encerra retornando o booleano `true`.

```cpp
    this->descritor.tamanho_fila++;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Remover

O método utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo FilaDinamica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, um ponteiro para `No`, denominado `removido` é inicializado apontando para o primeiro nó do encadeamento, em seguida uma variável `Individuo`: individuo é inicializada, recebendo o `Individuo` armazenado no ponteiro `removido`.

```cpp
	No *removido = this->descritor.primeiro;
	Individuo individuo = removido->individuo;
```

Por fim, o ponteiro `primeiro` do descritor é apontado para o ponteiro `proximo` do ponteiro `removido`, o `No` do ponteiro `removido` é liberado da memória, a variável `tamanho_fila` do descritor é decrementada em uma unidade e o método é encerrado, retornando a variável individuo.

```cpp

    this->descritor.primeiro = removido->proximo;

    delete removido;
    this->descritor.tamanho_fila--;

    return individuo;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a lista está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo FilaDinamica::buscar(int id)
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
    No *atual = this->descritor.primeiro;

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
    
	return atual->individuo;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub>



## Imprimir

O método utiliza um ponteiro para o início do encadeamento denominado `atual` e um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
void FilaDinamica::imprimir()
{
    No *atual = this->descritor.primeiro;

    while (atual != NULL)
    {
```

A cada etapa do loop as informações do `Individuo` armazenado no ponteiro `atual` são impressas no console e o ponteiro `atual` recebe o próximo nó do encadeamento.

```cpp
        cout << "\tIndivíduo id: " << atual->individuo.get_id() << ", ";
        cout << "Nome: " << atual->individuo.get_nome() << endl;

        atual = atual->proximo;
    }
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>

