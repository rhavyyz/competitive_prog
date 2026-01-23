# Upsolving MFP Final 2024

Algumas questões ainda não foram resolvidas e com o tempo serão adicionadas ao upsolving

### A

É simples visualizar a construção da solução da seguinte forma:

Uma arvore binaria!

```
           ______________D_____________
          |                            |
    ______C_______              _______C______
   |             |             |              |
___B___       ___B___       ___B___        ___B___
|     |       |     |       |     |        |     |
A     A       A     A       A     A        A     A
```

Assim, podemos criar uma função recursiva que gera um string, ou printa os caracteres seguindo uma [travessia inorder](https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/)

[Solução](/2024_final/src/a.cpp)

### C

Para encontrar um valor valido para $X$, o comprimento da volta, devemos ter garantia das seguintes condições:

- $A\% X = 0$

    - Significando que o competidor vencedor encerrou de fato no fim de uma volta, portanto obrigatoriamente em um multiplo do tamanho.

e

- $ [(A/X)-1] * X \leq B$
    - Significando que o perdedor percorreu distancia o suficiente para estar contido na ultima volta, ou seja, tendo passado da marca dos $(Quantidade\_de\_Voltas - 1)*X$.

Todos os possiveis valores de $X$ estão, obrigatoriamente, no intervalo $[1, A]$ e com o valor de $A\leq10^5$, é plenamente possivel iterar em todo o intervalo fazendo uma solução $O(A)$.

Caso $A$ tivesse um limite mais alto, ex $A\leq 10^9$, teriamos que reduzir o intervalo de busca. Conseguimos limita-lo obtendo $O(\sqrt A)$, utilizando uma estrategia analoga a de [descobrir se um numero é primo em $O(\sqrt A)$](https://www.geeksforgeeks.org/check-for-prime-number/#expected-approach-2-optimized-trial-division-method).

[Solução](/2024_final/src/c.cpp)

### D

Considerando o seguinte vetor $V=[0, 1, 2, 3, 4, 5]$, na posição $V_i$ teremos representada a função do jogador $i$. Podemos usar esse vetor para consultar na matriz quantos pontos essa configuração nos daria (pegando  valor da coluna $i$ e linha $V_i$). Assim, gerando [todas as permutações](https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/) do vetor $V$, e testamos para cada um dos cenarios possiveis, retornando a maior quantidade de pontos obtida. Veja que $!6 = 720$, então temos pouquissimas operações.

Um detalhe é que a implementação exige o uso de [long long](https://stackoverflow.com/questions/18971732/what-is-the-difference-between-long-long-long-long-int-and-long-long-i)

[Solução](/2024_final/src/d.cpp)

### F

Para resolver essa questão é importante conhecer o [algorithmo de Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)

É uma adaptação de dijkstra. Ao inves de orientar travessia pelo menor tamanho de caminho até o vertice atual, orientamos pelo maior tamanho da menor aresta encontrada durante a travessia até o vertice atual.

[Solução](/2024_final/src/f.cpp)

### H

Percorreremos os clientes por ordem de chegada.

Quando um novo cliente chegar, verificamos se um funcionario esta disponivel para atende-lo, caso sim, adicionaremos ele a alguma estrutura que os ordene os clientesz de acordo com a previsão do momento em que devem sair.

Caso o contrario, esse cliente vai para uma fila de espera na qual clientes são atendidos pela ordem de chegada.

Agora, com as duas estruturas (a que mantem os clientes que estão em atendimento e a fila dos em espera) antes de receber um novo cliente devemos:

- Eliminar da lista de clientes em atendimento todos os clientes que terminaram de ser atendidos antes da chegada do novo cliente 

e

- Receber quantos clientes em espera for possível.

A logica de atender caso existam funcionarios disponiveis e mover para espera se mantem exatamente igual.

No fim so devemos pegar o maior valor da quantidade de clientes que estão sendo atendidos $+$ quantidade de clientes em espera que ocorrer. 

[Solução](/2024_final/src/h.cpp)

### I

Devemos tratar uma linha como um vetor de strings contendo as palavras que compoem a linha.

Armazenando as linhas e utilizando um map para mapear o quanto cada palavra vale, se deve:

- Iterar entre as linhas.
- Iterar entre cada palavra da linha em questão
- Verificar se o valor da palavra em questão existe no map, caso exista se adiciona esse valor a uma variavel
- Tendo percorrido todas as palavras da linha atual, se verifica se o valor é maior ou igual ao maior valor ja encontrado. Sendo maior, substitua o valor e salve index da linha atual
- Adicione o valor do somatorio das palavras da linha atual a uma variavel que agrega a soma de todas as linhas

[Solução](/2024_final/src/i.py)
