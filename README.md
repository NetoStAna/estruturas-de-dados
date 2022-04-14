# Estruturas de Dados

Repositório contendo estudos de estruturas de dados desenvolvidos na linguagem C++.



## Tipo de Dado

Todas as estruturas seguem um padrão de desenvolvimento único e armazenam os dados de uma classe denominada `Individuo`, contendo as variáveis `int`: id e idade; `float`: peso e altura; e `string`: nome, assim como os respectivos métodos `get` de cada uma destas e `set` das variáveis que podem mudar ao longo do tempo.

```cpp
class Individuo
{
private:
    int id, idade;
    float peso, altura;
    string nome;
public:
    Individuo();
    Individuo(int id, int idade, float peso, float altura, string nome);

    int get_id();

    int get_idade();
    void set_idade(int idade);

    float get_peso();
    void set_peso(float peso);

    float get_altura();
    void set_altura(float altura);

    string get_nome();
};
```

Um construtor padrão para a classe `Individuo` também foi desenvolvido para fornecer o preenchimento automático de algumas estruturas específicas.

```cpp
Individuo::Individuo()
{
    this->id = -1;
    this->idade = 0;
    this->peso = 0;
    this->altura = 0;
    this->nome = "";
}
```



## Métodos

Quanto às estruturas em si, estas também estão desenvolvidas em forma de classe e possuem, para além de seus métodos construtores e destrutores específicos, sete métodos padrões que seguem o mesmo desenvolvimento.

### Está Vazia

```cpp
bool esta_vazia();
```

Este método verifica a ausência de elementos na estrutura de dados e é utilizado principalmente para evitar buscas desnecessárias.

### Está cheia

```cpp
bool esta_cheia();
```

Este método verifica se ainda há espaço de armazenamento na estrutura e é utilizado principalmente no controle do fluxo de inserção de elementos.

### Quantidade de Itens

```cpp
int quantidade_itens();
```

Este método retorna a quantidade de elementos válidos dentro da estrutura, excluindo os elementos preenchidos com as informações do construtor padrão da classe `Individuo`.

### Inserir

```cpp
bool inserir(Individuo individuo);
```

Método utilizado para inserir um `Individuo` na estrutura, pode retornar `true` quando o elemento é inserido com sucesso, ou `false` quando ocorre algum erro.

### Remover

```cpp
Individuo remover(int id);
```

Método utilizado para remover um `Individuo` da estrutura, utiliza o `id` do `Individuo` a ser removido como parâmetro, ou atua sem parâmetros quando a estrutura possui critérios específicos de ordem de remoção. Retorna o `Individuo` removido em caso de sucesso, ou um `Individuo` genérico do construtor padrão em caso de falha.

### Buscar

```cpp
Individuo buscar(int id);
```

Método utilizado para buscar um elemento na estrutura, utiliza sempre o `id` do `Individuo` a ser buscado como parâmetro e retorna o mesmo em caso de sucesso. Em caso de falha um `Individuo` genérico do construtor padrão é retornado.

### Imprimir

```cpp
void imprimir();
```

Este método imprime a estrutura de dados de acordo com a ordem em que seus elementos estão inseridos.



## Estruturas

### [Lista Sequencial Estática](01_lista_sequencial_estatica/README.md)

Armazena os dados de cada `Individuo` em um `vetor` com tamanho alocado pelo usuário no tempo de execução.

### [Lista Sequencial Dinâmica](02_lista_sequencial_dinamica/README.md)

Armazena os dados de cada `Individuo` em diferentes formas de listas encadeadas.

### [Fila (`FIFO`)](03_fila/README.md)

Armazena os dados de cada `Individuo` em forma de fila, onde o primeiro elemento da fila é o primeiro a ser removido.

### [Pilha (`LIFO`)](04_pilha/README.md)

Armazena os dados de cada `Individuo` em forma de pilha, onde o último elemento da pilha é o primeiro a ser removido.

### [Tabela Hash](05_tabela_hash/README.md)

Armazena os dados de cada `Individuo` em um `vetor` na posição respectiva ao resultado de uma `função hash` aplicada sobre o seu `id`. Diferentes formas de tratamento de colisões estão apresentadas.



## Referência

As estruturas apresentadas neste repositório partem de estudos iniciados no curso de [estrutura de dados](https://www.youtube.com/playlist?list=PLrOyM49ctTx_AMgNGQaic10qQJpTpXfn_) do canal do [Professor Douglas Maioli](https://www.youtube.com/c/ProfessorDouglasMaioli) no YouTube.
