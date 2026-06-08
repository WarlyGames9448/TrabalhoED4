#include <iostream>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp" 

int main() {

    Trie trie;
    

    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }

    std::cout << numberOfGames << " jogos inseridos na Trie.\n\n";

    // Teste de busca
    std::cout << "Testando o metodo contains com a base\n";
    // retorno 1
    std::cout << "Busca 'Hades' -> retorno: " << trie.contains("Hades") << "\n";
    std::cout << "Busca 'hollow knight' -> retorno: " << trie.contains("hollow knight") << "\n";
    std::cout << "Busca 'PORTAL 2' -> retorno: " << trie.contains("PORTAL 2") << "\n";
    std::cout << "Busca 'Team Fortress 2' -> retorno: " << trie.contains("Team Fortress 2") << "\n";
    std::cout << "Busca 'Half Life 2' -> retorno: " << trie.contains("Half Life") << "\n";

    // retorno
    std::cout << "\nBusca 'bomba patch 100percent atualizado geomatrix'  -> retorno: " << trie.contains("'bomba patch 100percent atualizado geomatrix") << "\n";
    std::cout << "Busca 'Had' -> retorno: " << trie.contains("Had") << "\n";


    return 0;
}