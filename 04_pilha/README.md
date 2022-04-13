# Pilha (`LIFO`)

Armazena os dados de cada `Individuo` em forma de pilha, onde o último elemento da pilha é o primeiro a ser removido.



## [Pilha Estática](01_pilha_estatica/README.md)

Armazena os dados de cada `Individuo` em forma de pilha, dentro de um `vetor` com tamanho alocado pelo usuário no tempo de execução.

A pilha é inicializada com as variáveis `int`: quantidade_itens e capacidade_max, assim como um ponteiro `pilha` para um vetor de objetos do tipo `Individuo`.



## [Pilha Dinâmica](02_pilha_dinamica/README.md)

Armazena os dados de cada `Individuo` em forma de pilha, através de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A pilha é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o último nó inserido no encadeamento, denominado `topo`, e uma variável `int`: tamanho_pilha para armazenar a quantidade de nós no encadeamento.
