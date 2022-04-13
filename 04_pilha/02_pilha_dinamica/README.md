# Pilha Dinâmica

Armazena os dados de cada `Individuo` em forma de pilha, através de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

```cpp
struct No
{
    Individuo individuo;
    No *proximo;
};
```

A pilha é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o último nó inserido no encadeamento, denominado `topo`, e uma variável `int`: tamanho_pilha para armazenar a quantidade de nós no encadeamento.

 ```cpp
 struct Descritor
 {
     No *topo;
     int tamanho_pilha;
 };
 
 class PilhaDinamica
 {
 private:
     Descritor descritor;
 ```



## Construtor

A estrutura é construída apontando o ponteiro `topo` do descritor para o valor `NULL`, assim como inicializando a variável `tamanho_pilha` do descritor em `0`.

```cpp
PilhaDinamica::PilhaDinamica()
{
    this->descritor.topo = NULL;
    this->descritor.tamanho_pilha = 0;
}
```



## Destrutor

A estrutura é destruída utilizando-se um ponteiro para `No` auxiliar, denominado `temp`, assim como um loop `while` que segue enquanto o ponteiro `topo` do descritor for diferente de `NULL`.

```cpp
PilhaDinamica::~PilhaDinamica()
{
    No *temp;

    while (this->descritor.topo != NULL)
    {
```

A cada etapa do loop, o ponteiro `temp` recebe o ponteiro `topo` do descritor, o ponteiro `topo` do descritor passa para o próximo nó do encadeamento. e o nó do ponteiro `temp` é liberado da memória. Ao fim do loop todos os nós do encadeamento são liberados, encerrando o método.

```cpp
        temp = this->descritor.topo;
        this->descritor.topo = this->descritor.topo->proximo;

        delete temp;
    }
}
```



## Está Vazia

O método retorna o valor da comparação entre o ponteiro `topo` do descritor e o valor `NULL`.

```cpp
bool PilhaDinamica::esta_vazia()
{
    return (this->descritor.topo == NULL);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Está cheia

O método utiliza um ponteiro para `No` denominado `temp` e um operador `try` e `catch` para verificar se ainda há espaço em memória para realizar a criação de um novo `No`.

```cpp
bool PilhaDinamica::esta_cheia()
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



## Tamanho da Pilha

O método retorna o valor armazenado na variável `tamanho_pilha` do descritor.

```cpp
int PilhaDinamica::tamanho_pilha()
{
    return this->descritor.tamanho_pilha;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Inserir

O método recebe um `Individuo` como parâmetro e verifica se a pilha está cheia. Em caso afirmativo, o método é encerrado, retornando o booleano `false`.

```cpp
bool PilhaDinamica::inserir(Individuo individuo)
{
    if (this->esta_cheia())
    {
        cout << "Indivíduo id: " << individuo.get_id() << " não inserido, pois a lista está cheia!\n";

        return false;
    }
```

Caso contrário, um novo nó é inicializado, recebendo o `Individuo` do parâmetro e com o ponteiro do próximo nó apontado para o `No` no topo do encadeamento.

```cpp
    No *novo = new No;
    novo->individuo = individuo;
    novo->proximo = this->descritor.topo;
```

Em seguida, o ponteiro `topo` do descritor é apontado para o novo `No`, inserindo-o desta forma no topo do encadeamento. Por fim, a variável `tamanho_pilha` do descritor é incrementada em uma unidade e o método é encerrado, retornando o booleano `true`.

```cpp
    this->descritor.topo = novo;
    this->descritor.tamanho_pilha++;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(1)</sub>



## Remover

O método utiliza uma variável `Individuo`: generico, inicializada pelo construtor padrão e verifica se a pilha está vazia. Em caso afirmativo, o método é encerrado e retorna a variável generico.

```cpp
Individuo PilhaDinamica::remover()
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a remover!\n";

        return generico;
    }
```

Caso contrário, um ponteiro para `No`, denominado `removido` é inicializado apontando para o topo do encadeamento, em seguida uma variável `Individuo`: individuo é inicializada, recebendo o `Individuo` armazenado no ponteiro `removido`.

```cpp
	No *removido = this->descritor.topo;
	Individuo individuo = removido->individuo;
```

Por fim, o ponteiro `topo` do descritor é apontado para o ponteiro `proximo` do ponteiro `removido`, o `No` do ponteiro `removido` é liberado da memória, a variável `tamanho_pilha` do descritor é decrementada em uma unidade e o método é encerrado, retornando a variável individuo.

```cpp

    this->descritor.topo = removido->proximo;

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
Individuo PilhaDinamica::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A lista está vazia, nada a buscar!\n";

        return generico;
    }
```

Em caso negativo são utilizados um ponteiro para `No` apontado para o topo do encadeamento, denominado `atual` e um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL` e o `id` do `Individuo` armazenado no ponteiro `atual` for diferente do `id` recebido como parâmetro.

```cpp
    No *atual = this->descritor.topo;

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

O método utiliza um ponteiro para o topo do encadeamento denominado `atual` e um loop `while` que segue enquanto o ponteiro `atual` for diferente de `NULL`.

```cpp
void PilhaDinamica::imprimir()
{
    No *atual = this->descritor.topo;

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

