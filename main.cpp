#include <iostream>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./app k prefix" << std::endl;
        return 1;
    }

    Trie trie;

    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }

    int k = std::atoi(argv[1]);
    std::string prefix = argv[2];

    std::vector<Game*> games = trie.autocomplete(prefix, k);

    if(games.size() == 0){
        std::cout << "No results found" << std::endl;
        return 0;
    }

    for(auto game : games){
        std::cout << game->getTitle() << " | " << game->getShortDescription() << " | " << game->getPopularity() << std::endl;
    }

    return 0;
}
