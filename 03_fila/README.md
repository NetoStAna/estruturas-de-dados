# Fila (`FIFO`)

Armazena os dados de cada `Individuo` em forma de fila, onde o primeiro elemento da fila é o primeiro a ser removido.



## [Fila Estática](01_fila_estatica/README.md)

Armazena os dados de cada `Individuo` em forma de fila, ordenada por ordem de inserção, dentro de um `vetor` com tamanho alocado pelo usuário no tempo de execução.

A fila é inicializada com as variáveis `int`: primeiro, ultimo e capacidade_max, assim como um ponteiro `fila` para um vetor de objetos do tipo `Individuo`.



## [Fila Dinâmica](02_fila_dinamica/README.md)

Armazena os dados de cada `Individuo` em forma de fila, ordenada por ordem de inserção, através de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento, um ponteiro apontado para o último nó do encadeamento e uma variável `int`: tamanho_fila para armazenar a quantidade de nós no encadeamento.



## [Fila de Prioridades](03_fila_prioridades/README.md)

Armazena os dados de cada `Individuo` em forma de fila, ordenada pela variável `int`: idade, através de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A lista é inicializada com um `struct` denominado `Descritor`, contendo um ponteiro apontado para o primeiro nó do encadeamento e uma variável `int`: tamanho_fila para armazenar a quantidade de nós no encadeamento.

