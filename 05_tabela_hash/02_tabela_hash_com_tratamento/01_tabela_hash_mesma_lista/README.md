# Colisões na Mesma Lista

Insere as colisões na mesma lista, utilizando a próxima posição disponível no `vetor`.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela, `int`: capacidade_max, para indicar a quantidade máxima de posições disponíveis no `vetor` e `int`: tamanho_total, para indicar a quantidade total de posições no `vetor`, assim como um ponteiro `tabela` para um `vetor` de objetos do tipo `Individuo`.

 ```cpp
 class TabelaHash
 {
 private:
     int funcao_hash(int id);
     int quantidade_itens, capacidade_max, tamanho_total;
     Individuo *tabela;
 ```



## Construtor

A estrutura é construída inicializando-se a variável `quantidade_itens` em `0`, a variável `capacidade_max` com um valor definido pelo usuário, assim como alocando-se o espaço de um `vetor` de objetos do tipo `Individuo` através de uma quantidade máxima de elementos definida pelo usuário e armazenada na variável `tamanho_total`. 

```cpp
TabelaHash::TabelaHash(int capacidade_max, int tamanho_total)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->tamanho_total = tamanho_total;
    this->tabela = new Individuo[this->tamanho_total];
}
```



## Destrutor

A estrutura é destruída ao liberar o espaço da memória onde o `vetor` foi alocado.

```cpp
TabelaHash::~TabelaHash()
{
    delete [] this->tabela;
}
```



## Está Vazia

O método retorna o valor da igualdade entre o valor armazenado na variável `quantidade_itens` e o valor `0`.

```cpp
bool TabelaHash::esta_vazia()
{
    return (this->quantidade_itens == 0);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



## Está Cheia

O método retorna o valor da igualdade entre o valor armazenado na variável `quantidade_itens` e o valor armazenado na variável `capacidade_max`.

```cpp
bool TabelaHash::esta_cheia()
{
    return (this->quantidade_itens == this->capacidade_max);
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao. Em seguida, é iniciado um loop `while` que segue enquanto o `id` do `Individuo` armazenado na posição correspondente for diferente de `-1` e `-2`.

```cpp
    int posicao = this->funcao_hash(individuo.get_id());

    while (this->tabela[posicao].get_id() != -1 && this->tabela[posicao].get_id() != -2)
    {
```

A cada etapa do loop a variável `posicao` recebe o valor do resto da divisão dela própria, incrementada em uma unidade, pelo valor da variável `tamanho_total`. Ao fim do loop, o `Individuo` recebido é inserido na posição correspondente da tabela, o valor da variável `quantidade_itens` é incrementado em uma unidade e o método é encerrado, retornando o booleano `true`.

```cpp
        posicao = (posicao + 1) % this->tamanho_total;
    }
    this->tabela[posicao] = individuo;
    this->quantidade_itens++;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Bastante Improvável)_



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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao, em seguida, é utilizado um loop `while` que segue enquanto o `id` do `Individuo` da posição correspondente for diferente de `-1`.

```cpp
	int posicao = this->funcao_hash(id);

	while (this->tabela[posicao].get_id() != -1)
    {
```

A cada etapa do loop é comparado o valor do `id` do `Individuo` armazenado na posição correspondente, ao `id` recebido como parâmetro. Em caso positivo, o `Individuo` armazenado na posição correspondente é recebido por uma variável `Individuo`: individuo, a posição correspondente na tabela recebe um `Individuo` com `id -2`, representando um espaço removido, a variável `quantidade_itens` é decrementada em uma unidade e o método é encerrado retornando a variável `individuo`.

```cpp
        if (this->tabela[posicao].get_id() == id)
        {
            Individuo individuo = this->tabela[posicao];

            this->tabela[posicao] = Individuo(-2, 0, 0, 0, "");
            this->quantidade_itens--;

            return individuo;
        }
```

Caso contrário, a variável `posicao` recebe o valor do resto da divisão dela própria, incrementada em uma unidade, pelo valor da variável `tamanho_total` e o loop continua. Caso o loop encerre sem encontrar um `Individuo` com `id` igual ao recebido como parâmetro, o método é encerrado, retornando a variável `generico`.

```cpp
        posicao = (posicao + 1) % this->tamanho_total;
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}
```

>  Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Bastante Improvável)_



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`:  generico, inicializada pelo construtor padrão e verifica se a tabela está  vazia. Em caso afirmativo o método é encerrado e retorna a variável  `generico`.

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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao, em seguida, é utilizado um loop `while` que segue enquanto o `id` do `Individuo` da posição correspondente for diferente de `-1`.

```cpp
	int posicao = this->funcao_hash(id);

	while (this->tabela[posicao].get_id() != -1)
	{
```

A cada etapa do loop é comparado o valor do `id` do `Individuo` armazenado na posição correspondente, ao `id` recebido como parâmetro. Em caso positivo, o método é encerrado e o `Individuo` armazenado na posição correspondente é retornado.

```cpp
        if (this->tabela[posicao].get_id() == id)
        {
            return this->tabela[posicao];
        }
```

Caso contrário, a variável `posicao` recebe o valor do resto da divisão dela própria, incrementada em uma unidade, pelo valor da variável `tamanho_total` e o loop continua. Caso o loop encerre sem encontrar um `Individuo` com `id` igual ao recebido como parâmetro, o método é encerrado, retornando a variável `generico`.

```cpp
        posicao = (posicao + 1) % this->tamanho_total;
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}
```

>  Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Bastante Improvável)_



## Imprimir

O método utiliza um laço `for` que percorre toda a tabela.

```cpp
void TabelaHash::imprimir()
{
    for (int i = 0; i < this->tamanho_total; i++)
    {
```

A cada etapa do laço, se o `id` do `Individuo` armazenado na posição `i` for maior que o `id` do construtor padrão, seus dados são impressos no console.

```cpp
		if (this->tabela[i].get_id() > -1)
        {
            cout << "\tIndivíduo id: " << this->tabela[i].get_id() << ", ";
            cout << "Nome: " << this->tabela[i].get_nome() << endl;
        }
	}
}
```

> Melhor caso: O<sub>(n)</sub>
>
> Pior caso: O<sub>(n)</sub>
