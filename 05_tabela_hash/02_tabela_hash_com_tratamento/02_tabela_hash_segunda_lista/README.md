 

# Colisões em Lista Separada

Insere as colisões em uma lista auxiliar, utilizando a próxima posição disponível desta.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela, `int`: ultima_colisao, para indicar a posição de inserção da próxima colisão, `int`: capacidade_tabela, para indicar a quantidade de posições no `vetor` principal e `int`: capacidade_colisoes, para indicar a quantidade de posições no `vetor` das colisões, assim como dois ponteiros `tabela` e `colisoes` para dois `vetores` de objetos do tipo `Individuo`.

```cpp
class TabelaHash
{
private:
    int funcao_hash(int id);
    int quantidade_itens, ultima_colisao, capacidade_tabela, capacidade_colisoes;
    Individuo *tabela, *colisoes;
```



## Construtor

## Construtor

A estrutura é construída inicializando-se as variáveis `quantidade_itens` e `ultima_colisao` em `0`, assim como alocando-se o espaço de dois `vetores` de objetos do tipo `Individuo`, um através de uma quantidade máxima de elementos definida pelo usuário e armazenada na variável `capacidade_tabela` e outro através do valor definido pelo usuário para a variável `capacidade_colisoes`. 

```cpp
TabelaHash::TabelaHash(int capacidade_tabela, int capacidade_colisoes)
{
    this->quantidade_itens = 0;
    this->ultima_colisao = 0;
    this->capacidade_tabela = capacidade_tabela;
    this->capacidade_colisoes = capacidade_colisoes;
    this->tabela = new Individuo[this->capacidade_tabela];
    this->colisoes = new Individuo[this->capacidade_colisoes];
}
```



## Destrutor

A estrutura é destruída ao liberar o espaço da memória onde os `vetores` foram alocados.

```cpp
TabelaHash::~TabelaHash()
{
    delete [] this->tabela;
    delete [] this->colisoes;
}
```



## Está Vazia

O método recebe uma variável `int`: id como parâmetro e o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao. Em seguida, é verificada a igualdade do `id` do `Individuo` armazenada na posição correspondente ao valor do construtor padrão `-1`. Caso estes sejam diferentes, o método é encerrado, retornando o booleano `false`.

```cpp
bool TabelaHash::esta_vazia(int id)
{
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() != -1)
    {
        return false;
    }
```

Caso contrário, um laço `for` que pode percorrer toda a tabela de colisões é utilizado. A cada etapa do laço, o `id` do `Individuo` armazenado na posição `i` é comparado ao `id` do construtor padrão `-1`. Caso estes sejam diferentes, o método é encerrado e retorna o booleano `false`.

```cpp
    
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() != -1)
        {
            return false;
        }
```

Caso o laço seja completado sem encontrar um `Individuo` com `id` diferente de `-1`, o método é encerrado, retornando o booleano `true`.

```cpp
    }

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Tabela de Colisões)_



## Está Cheia

O método recebe uma variável `int`: id como parâmetro e o valor da função `funcao_hash`, aplicada sobre o `id` recebido é armazenado em uma variável `int`: posicao. Em seguida, é verificada a igualdade do `id` do `Individuo` armazenada na posição correspondente ao valor do construtor padrão `-1`. Caso estes sejam iguais, o método é encerrado, retornando o booleano `false`.

```cpp
bool TabelaHash::esta_cheia(int id)
{
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == -1)
    {
        return false;
    }
```

Caso contrário, um laço `for` que pode percorrer toda a tabela de colisões é utilizado. A cada etapa do laço, o `id` do `Individuo` armazenado na posição `i` é comparado ao `id` do construtor padrão `-1`. Caso estes sejam iguais, o método é encerrado e retorna o booleano `false`.

```cpp
    
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() == -1)
        {
            return false;
        }
```

Caso o laço seja completado sem encontrar um `Individuo` com `id` igual a `-1`, o método é encerrado, retornando o booleano `true`.

```cpp
    }

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Tabela de Colisões)_



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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao. Em seguida, o valor do `id` do `Individuo` armazenado na posição correspondente é comparado ao valor do construtor padrão, `-1`, em caso afirmativo, a variável `individuo` é inserida na posição correspondente da tabela.

```cpp
    int posicao = this->funcao_hash(individuo.get_id());

    if (this->tabela[posicao].get_id() == -1)
    {
        this->tabela[posicao] = individuo;
    }
```

Caso contrário, a variável `individuo` é inserida na tabela de colisões, na posição correspondente ao resto da divisão do valor armazenado na variável `ultima_colisao` pelo valor da variável `capacidade_colisoes`, em seguida, a variável `ultima_colisao` é incrementada em uma unidade.

```cpp
    else
    {
        this->colisoes[this->ultima_colisao % this->capacidade_colisoes] = individuo;
        this->ultima_colisao++;
    }
```

Por fim, a variável `quantidade_itens` é incrementada em uma unidade e o método é encerrado, retornando o booleano `true`.

```cpp
    this->quantidade_itens++;

    return true;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Tabela de Colisões)_



## Remover

O método recebe uma variável `int`: id como parâmetro, utiliza uma variável `Individuo`:  generico, inicializada pelo construtor padrão e verifica se a tabela está  vazia. Em caso afirmativo o método é encerrado e retorna a variável  `generico`.

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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao. Em seguida, o valor do `id` do `Individuo` armazenado na posição correspondente é comparado ao `id` recebido como parâmetro, caso estes sejam iguais uma variável `Individuo`: individuo recebe o `Individuo` armazenado na posição correspondente, a posição correspondente na tabela recebe a variável `generico`, a variável `quantidade_itens` é decrementada em uma unidade e o método é encerrado, retornando a variável `individuo`.

```cpp
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == id)
    {
        Individuo individuo = this->tabela[posicao];
        this->tabela[posicao] = generico;
        this->quantidade_itens--;

        return individuo;
    }
```

Caso contrário, um laço `for` que pode percorrer toda a tabela de colisões é utilizado. A cada etapa do laço, o `id` do `Individuo` armazenado na posição `i` é comparado ao `id` recebido como parâmetro, caso estes sejam iguais, o `Individuo` armazenado na posição `i` da tabela de colisões é recebido por uma variável `Individuo`: individuo, a posição correspondente recebe a variável `generico`, a variável `quantidade_itens` é decrementada em uma unidade e o método é encerrado, retornando a variável `individuo`.

```cpp
    else
    {
        for (int i = 0; i < this->capacidade_colisoes; i++)
        {
            if (this->colisoes[i].get_id() == id)
            {
                Individuo individuo = this->colisoes[i];
                this->colisoes[i] = generico;
                this->quantidade_itens--;

                return individuo;
            }
```

Caso o laço seja encerrado sem encontrar um `Individuo` correspondente, o método é encerrado, retornando a variável `generico`.

```cpp
        }
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Tabela de Colisões)_



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

Caso contrário, o valor da função `funcao_hash`, aplicada sobre o `id` do `Individuo` é armazenado em uma variável `int`: posicao. Em seguida, o valor do `id` do `Individuo` armazenado na posição correspondente é comparado ao `id` recebido como parâmetro, caso estes sejam iguais o `Individuo` armazenado na posição correspondente é retornado e o método é encerrado.

```cpp
    int posicao = this->funcao_hash(id);

    if (this->tabela[posicao].get_id() == id)
    {
        return this->tabela[posicao];
    }
```

Caso contrário, um laço `for` que pode percorrer toda a tabela de colisões é utilizado. A cada etapa do laço, o `id` do `Individuo` armazenado na posição `i` é comparado ao `id` recebido como parâmetro, caso estes sejam iguais, o `Individuo` armazenado na posição `i` da tabela de colisões é retornado e o método é encerrado.

```cpp
    else
    {
        for (int i = 0; i < this->capacidade_colisoes; i++)
        {
            if (this->colisoes[i].get_id() == id)
            {
                return this->colisoes[i];
            }
```

Caso o laço seja encerrado sem encontrar um `Individuo` correspondente, o método é encerrado, retornando a variável `generico`.

```cpp
        }
    }
    cout << "Indivíduo id: " << id << " não se encontra na tabela!\n";

    return generico;
}
```

> Melhor caso: O<sub>(1)</sub>
>
> Pior caso: O<sub>(n)</sub> _(Tabela de Colisões)_



## Imprimir

O método utiliza dois laços `for` que percorrem a tabela hash e a tabela de colisões. A cada etapa dos laços, o `id` do `Individuo` correspondente à posição `i` da respectiva tabela é comparado ao valor do construtor padrão, `-1`. Caso estes sejam diferentes, as informações do `Individuo` são impressas no console.

```cpp
void TabelaHash::imprimir()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < this->capacidade_tabela; i++)
    {
        if (this->tabela[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->tabela[i].get_id() << ", ";
            cout << "Nome: " << this->tabela[i].get_nome() << endl;
        }
    }

    cout << "\n";

    cout << "Tabela de Colisões:\n";
    for (int i = 0; i < this->capacidade_colisoes; i++)
    {
        if (this->colisoes[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->colisoes[i].get_id() << ", ";
            cout << "Nome: " << this->colisoes[i].get_nome() << endl;
        }
    }
}
```

> Melhor Caso: O<sub>(n)</sub>
>
> Pior Caso: O<sub>(n)</sub>
