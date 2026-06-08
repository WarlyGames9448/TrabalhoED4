#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <vector>
#include "Game.hpp"

const int ALPHABET_SIZE = 36;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;
    int getCharIndex(char c);

public:
    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);
    std::vector<Game*> autocomplete(std::string prefix, int k);
    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

private:
    void QuickSort(std::vector<Game*>& games, int low, int high);
    int Partition(std::vector<Game*>& games, int low, int high);
    bool isBefore(Game* a, Game* b);

    // Busca todos os games de uma subárvore e os adiciona em foundgames;
    void searchGames(TrieNode* node, std::vector<Game*>& foundgames);
};

#endif
