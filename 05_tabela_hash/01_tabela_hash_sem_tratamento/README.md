# Tabela Hash sem Tratamento de Colisões

 Armazena os dados de cada `Individuo` na tabela hash sem tratar possíveis colisões, ou seja, substituindo o `Individuio` já armazenado, pelo novo `Individuo` inserido.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela, e `int`: capacidade_max, para indicar a quantidade máxima de posições do `vetor`, assim como um ponteiro `tabela` para um `vetor` de objetos do tipo `Individuo`.

```cpp
class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, capacidade_max;
    Individuo *tabela;
```

 

## Construtor

A estrutura é construída inicializando-se a variável `quantidade_itens` em `0`, assim como alocando-se o espaço de um `vetor` de objetos do tipo `Individuo` através de uma quantidade máxima de elementos definida pelo usuário e armazenada na variável `capacidade_max`.

```cpp
TabelaHash::TabelaHash(int capacidade_max)
{
    this->quantidade_itens = 0;
    this->capacidade_max = capacidade_max;
    this->tabela = new Individuo[this->capacidade_max];
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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao. Em seguida, verifica-se se a posição do vetor está vazia, e em caso afirmativo acrescenta-se uma unidade à variável `quantidade_itens`.

```cpp
    int posicao = this->funcao_hash(individuo.get_id());

    if (this->tabela[posicao].get_id() == -1)
    {
        this->quantidade_itens++;
    }
```

Por fim, o `Individuo` recebido é inserido na posição correspondente e o método é encerrado, retornando o booleano `true`.

```cpp
    this->tabela[posicao] = individuo;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao e o `Inidividuo` armazenado na posição correspondente é recebido por uma variável `Individuo`: individuo. Em seguida, verifica-se a igualdade entre o `id` da variável `individuo` e o `id` recebido, caso estes sejam diferentes, o método é encerrado, retornando a variável generico.

```cpp
    int posicao = this->funcao_hash(id);
    Individuo individuo = this->tabela[posicao];

    if (individuo.get_id() != id)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Caso contrário, a posição correspondente da tabela recebe a variável `generico`, a variável `quantidade_itens` é decrementada em uma unidade e o método é encerrado, retornando a variável `individuo`.

```cpp
    this->tabela[posicao] = generico;
    this->quantidade_itens--;

    return individuo;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



## Buscar

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`:  generico, inicializada pelo construtor padrão e verifica se a tabela está  vazia. Em caso afirmativo o método é encerrado e retorna a variável  generico.

```cpp
Individuo TabelaHash::buscar(int id)
{
    Individuo generico;

    if (this->esta_vazia())
    {
        cout << "A tabela está vazia, nada a buscar!\n";

        return generico;
    }
```

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao e o `Inidividuo` armazenado na posição correspondente é recebido por uma variável `Individuo`: individuo. Em seguida, verifica-se a igualdade entre o `id` da variável `individuo` e o `id` recebido, caso estes sejam diferentes, o método é encerrado, retornando a variável generico.

```cpp
    int posicao = this->funcao_hash(id);
    Individuo individuo = this->tabela[posicao];

    if (individuo.get_id() != id)
    {
        cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

        return generico;
    }
```

Caso contrário, o método é encerrado, retornando a variável `individuo`.

```cpp
    
    return individuo;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(1)</sub>



## Imprimir

O método utiliza um laço `for` que percorre toda a tabela.

```cpp
void TabelaHash::imprimir()
{
    for (int i = 0; i < this->capacidade_max; i++)
    {
```

A cada etapa do laço, se o `id` do `Individuo` armazenado na posição `i` for diferente do construtor padrão, seus dados são impressos no console.

```cpp
		if (this->tabela[i].get_id() != -1)
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
