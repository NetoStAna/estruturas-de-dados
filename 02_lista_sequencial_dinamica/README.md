# Lista Sequencial Dinâmica

 Armazena os dados de cada `Individuo` em diferentes formas de listas encadeadas.



## [Lista Encadeada](01_lista_encadeada/README.md)

Armazena os dados de cada `Individuo` em uma lista de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um ponteiro apontado para o primeiro nó do encadeamento.



## [Lista Encadeada com Nó Descritor](02_lista_encadeada_no_descritor/README.md)

Armazena os dados de cada `Individuo` em uma lista de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: quantidade_itens para armazenar a quantidade de nós no encadeamento.



## [Lista Duplamente Encadeada](03_lista_duplamente_encadeada/README.md)

Armazena os dados de cada `Individuo` em uma lista de nós encadeados em duas direções, sem laços, contendo um `struct` denominado `No`, composto por um ponteiro para o nó anterior do encadeamento, um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: quantidade_itens para armazenar a quantidade de nós no encadeamento.



## [Lista Circular](04_lista_circular/README.md)

Armazena os dados de cada `Individuo` em uma lista de nós encadeados em uma única direção, com um laço entre o primeiro e o último nó do encadeamento, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: quantidade_itens para armazenar a quantidade de nós no encadeamento.
