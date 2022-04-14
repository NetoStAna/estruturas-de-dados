# Tabela Hash

Armazena os dados de cada `Individuo` em um `vetor` na posição respectiva ao resultado de uma `função hash` aplicada sobre o seu `id`. Diferentes formas de tratamento de colisões estão apresentadas.



## Função Hash

A `função hash` recebe uma variável `int`: id como parâmetro e utiliza as variáveis `int`: resultado, exp e soma sendo as duas últimas inicializadas em `0`, assim como, um loop `while` que segue enquanto o a variável `id` for diferente de `0`.

```cpp
int TabelaHash::funcao_hash(int id)
{
    int resultado, exp = 0, soma = 0;
    
    while (id != 0)
    {
```

 A cada etapa do loop, a variável `resultado` recebe o valor da potenciação do último dígito da variável `id` (`id % 10`) elevado ao valor da variável `exp`. Em seguida, o valor da variável `resultado` é acrescentado à variável `soma`, o último dígito da variável `id` é descartado (`id /= 10`) e a variável `exp` é incrementada em uma unidade.

```cpp
		resultado = pow((id % 10), exp);
		soma += resultado;
		id /= 10;
		exp++;
```

Por fim, o resto da divisão da variável `soma`, pela quantidade máxima de elementos na tabela, é retornado, definindo a posição do `Individuo` no `vetor`.

```cpp
	}
	
	return (soma % this->capacidade_max);
}
```



## [Tabela Hash sem Tratamento de Colisões](01_tabela_hash_sem_tratamento/README.md)

 Armazena os dados de cada `Individuo` na tabela hash sem tratar possíveis colisões, ou seja, substituindo o `Individuio` já armazenado, pelo novo `Individuo` inserido.



## [Tabela Hash com Tratamento de Colisões](02_tabela_hash_com_tratamento/README.md)

Armazena os dados de cada `Individuo` na tabela hash com diferentes métodos de tratamento das colisões, ou seja, sem substituir o `Individuo` já armazenado, pelo novo `Individuo` inserido.
