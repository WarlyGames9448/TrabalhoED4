# Autocomplete de Jogos com Trie

Este projeto implementa uma estrutura de dados Trie (Árvore de Prefixos) em C++ desenvolvida para armazenar e buscar títulos de jogos eletrônicos, oferecendo suporte a busca exata e preenchimento automático (*autocomplete*) otimizado e ordenado por popularidade.

## Organização dos Arquivos

* `Trie.hpp` / `Trie.cpp`: Definição e implementação da árvore Trie, do nó (`TrieNode`) e algoritmos de ordenação.
* `Game.hpp` / `Game.cpp`: Interface e classe que encapsula os dados do jogo (título, popularidade, etc.).
* `GamesDatabase.hpp` / `GamesDatabase.cpp`: Gerenciamento e carga do vetor global de jogos.
* `main.cpp`: Interface de linha de comando e ponto de entrada do sistema.

## Compilação

Para compilar o projeto utilizando o `g++`:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

## Execução

```bash
./app k "prefix"
```

## Exemplo de Uso

```text
> ./app 5 "ho"
Hollow Knight | Forge your own path in Hollow Knight An epic action adventure through a vast ruined kingdom of insects and heroes Explore twisting caverns battle tainted creatures and befriend bizarre bugs all in a classic hand drawn 2D style | 269812
Hogwarts Legacy | Hogwarts Legacy is an immersive open world action RPG Now you can take control of the action and be at the center of your own adventure in the wizarding world | 154790
Horizon Zero Dawn Complete Edition | Experience Aloy s legendary quest to unravel the mysteries of a future Earth ruled by Machines Use devastating tactical attacks against your prey and explore a majestic open world in this award winning action RPG | 75057
Hotline Miami | Hotline Miami is a high octane action game overflowing with raw brutality hard boiled gunplay and skull crushing close combat | 72638
Hotline Miami 2 Wrong Number | Hotline Miami 2 Wrong Number is the brutal conclusion to the Hotline Miami saga set against a backdrop of escalating violence and retribution over spilled blood in the original game | 43726
```
