 

# Tabela Hash com Tratamento de Colisões

Armazena os dados de cada `Individuo` na tabela hash com diferentes métodos de tratamento das colisões, ou seja, sem substituir o `Individuo` já armazenado, pelo novo `Individuo` inserido.



## [Colisões na Mesma Lista](01_tabela_hash_mesma_lista/README.md)

Insere as colisões na mesma lista, utilizando a próxima posição disponível no `vetor`.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela, `int`: capacidade_max, para indicar a quantidade máxima de posições disponíveis no `vetor` e `int`: tamanho_total, para indicar a quantidade total de posições no `vetor`, assim como um ponteiro `tabela` para um `vetor` de objetos do tipo `Individuo`.



## [Colisões em Lista Separada](02_tabela_hash_segunda_lista/README.md)

Insere as colisões em uma lista auxiliar, utilizando a próxima posição disponível desta.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela, `int`: ultima_colisao, para indicar a posição de inserção da próxima colisão, `int`: capacidade_tabela, para indicar a quantidade de posições no `vetor` principal e `int`: capacidade_colisoes, para indicar a quantidade de posições no `vetor` das colisões, assim como dois ponteiros `tabela` e `colisoes` para dois `vetores` de objetos do tipo `Individuo`.



## [Colisões em Lista Encadeada](03_tabela_hash_lista_encadeada/README.md)

Insere as colisões em uma lista de nós encadeados em uma única direção, sem laços, contendo um `struct` denominado `No`, composto por um `Individuo` e um ponteiro para o próximo nó do encadeamento.

A tabela é inicializada com a função: `funcao_hash`, as variáveis `int`: quantidade_itens, para indicar a quantidade de itens inseridos na tabela e `int`: capacidade_max, para indicar a quantidade máxima de posições no `vetor`, assim como um ponteiro `tabela` para um `vetor` de ponteiros para `No`.

