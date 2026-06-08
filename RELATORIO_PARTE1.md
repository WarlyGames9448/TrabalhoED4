# Relatório: Sistema de Autocomplete de Jogos com Trie

## 1. Representação da Trie

### 1.1 Tamanho do Alfabeto

O alfabeto interno foi definido com 36 caracteres, divididos em:

* **Letras (a-z):** Índices 0 a 25.
* **Números (0-9):** Índices 26 a 35.

Símbolos e acentuações não são suportados, de acordo com o escopo do projeto.

### 1.2 Mapeamento de Caracteres

A conversão do caractere para sua posição no array de filhos é feita pelo método auxiliar `getCharIndex()`. Ele utiliza aritmética básica com os valores da tabela ASCII para mapear o caractere ao seu respectivo índice no array. Essa abordagem garante acesso direto em tempo constante, com custo $O(1)$.

### 1.3 Chave de Busca

Para garantir que a busca não seja sensível a maiúsculas, minúsculas ou espaçamentos irregulares, a função `toSearchKey()` atua como um filtro de entrada. Ela itera sobre a string original e gera uma chave interna:

1. Ignorando completamente os espaços em branco.
2. Convertendo letras para minúsculas.
3. Preservando números.

Dessa forma, entradas como `"Half Life"`, `"halflife"` e `"HALF LIFE"` produzem a mesma chave interna: `"halflife"`.

---

## 2. Funcionamento dos Métodos Básicos

### 2.1 Método `insert`

O processo de inserção obedece ao percurso padrão da estrutura Trie:

1. O título original é convertido pela função `toSearchKey()`.
2. A árvore é percorrida caractere por caractere a partir da raiz.
3. Se um nó correspondente ao caractere não existir, um novo `TrieNode` é alocado.
4. No nó correspondente ao último caractere da string, a flag `isEndOfTitle` é marcada como `true` e o nó recebe o ponteiro em memória do objeto `Game` associado.

### 2.2 Método `contains`

A verificação de existência exata converte o título de busca e percorre a árvore seguindo a chave formada. O método retorna `true` sob duas condições simultâneas: o percurso não foi interrompido (todos os nós da palavra existem) e o último nó alcançado está explicitamente marcado como final de título (`isEndOfTitle == true`).

### 2.3 Estrutura do Nó

A classe `TrieNode` foi projetada armazenando:

* Um array de 36 ponteiros para instâncias filhas.
* Um valor booleano indicador de fim de palavra.
* Um ponteiro direto para o jogo.

O gerenciamento de memória é tratado no destrutor de `TrieNode`, que libera recursivamente todos os nós alocados na subárvore para prevenir vazamento de memória.

---

## 3. Análise de Custo Computacional

Considerando $L$ como o tamanho da chave após a normalização e $M$ como o tamanho da string original informada pelo usuário:

* **`toSearchKey()`:** Custo de $O(M)$. A função exige uma única iteração linear pela string, aplicando regras de verificação com custo unitário $O(1)$ por caractere.
* **`insert()`:** Custo de $O(L)$. O método executa a normalização e percorre até $L$ nós na árvore. No pior caso (nenhum prefixo compartilhado), são criados $L$ nós.
* **`contains()`:** Custo de $O(L)$. O percurso de busca desce na árvore no máximo $L$ níveis antes de confirmar ou negar a existência da string.

---

## 4. Comparação: Trie vs Solução Ingênua

### 4.1 Custo de Busca

Em uma solução ingênua utilizando um array sequencial ou lista ligada, uma operação de busca por prefixo (autocomplete) exige iterar por todos os elementos. O custo seria de $O(N \times L)$, sendo $N$ o total de jogos cadastrados.
Na Trie, o autocomplete exige apenas caminhar até o fim do prefixo buscado e percorrer a subárvore resultante, resultando em um custo de $O(p + s)$, onde $p$ é o tamanho do prefixo e $s$ a quantidade de nós filhos diretos e indiretos associados àquela raiz.

### 4.2 Utilização de Memória e Prefixos Compartilhados

A Trie reduz significativamente o espaço gasto com redundância textual ao compartilhar prefixos comuns. Títulos como "Hades" e "Halo", por exemplo, utilizam o mesmo caminho na árvore para os caracteres "h" e "a".

Contudo, essa estrutura apresenta uma taxa elevada de consumo de memória devido à quantidade de ponteiros nulos. Em arquiteturas de 64 bits, cada `TrieNode` aloca 36 ponteiros (288 bytes), além do ponteiro de jogo e flag booleana, resultando em aproximadamente 300 bytes por caractere armazenado. Esse gasto extra de espaço é o custo arquitetural direto para se obter a melhora drástica no tempo de execução das buscas.

---

## 5. Decisões de Implementação

* **Uso de Ponteiros de Referência:** A árvore não armazena cópias das instâncias de `Game`, apenas ponteiros que apontam para o catálogo carregado originalmente. Isso evita a duplicação de dados em memória.
* **Travessia de Subárvore:** A operação de autocomplete coletará sugestões internamente utilizando uma busca em profundidade recursiva (DFS), reunindo todos os jogos alocados a partir da última letra do prefixo inserido pelo usuário.

> *Nota: As explicações detalhadas de funcionamento e custo dos métodos `sortResults()` e `autocomplete()` serão documentadas na etapa final de implementação.*