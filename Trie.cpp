#include "Trie.hpp"
#include <cctype>


TrieNode::TrieNode() {
    isEndOfTitle = false;
    game = nullptr;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (children[i] != nullptr) {
            delete children[i];
        }
    }
}


Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

int Trie::getCharIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if (c >= '0' && c <= '9') {
        return (c - '0') + 26;
    }
    return -1;
}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";
    
    for (char c : text) {
        if (c == ' ') {
            continue;
        }
        
        if (std::isalpha(c)) {
            key += std::tolower(c);
        } 
        else if (std::isdigit(c)) {
            key += c;
        }
    }
    
    return key;
}

bool Trie::insert(Game* game) {
    if (game == nullptr) {
        return false;
    }

    std::string key = toSearchKey(game->getTitle());
    TrieNode* current = root;

    for (char c : key) {
        int index = getCharIndex(c);
        if (index == -1) {
            continue;
        }

        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }

    current->isEndOfTitle = true;
    current->game = game;

    return true;
}

bool Trie::contains(std::string title) {
    std::string key = toSearchKey(title);
    TrieNode* current = root;

    for (char c : key) {
        int index = getCharIndex(c);
        if (index == -1) {
            continue;
        }

        if (current->children[index] == nullptr) {
            return false;
        }
        current = current->children[index];
    }

    return current != nullptr && current->isEndOfTitle;
}

void Trie::sortResults(std::vector<Game*>& games) {
    // implementar ordenação sem  std::sort com 1) popularidade decrescente e 2) ordem alfabética da chave de busca (crescente)
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {
    // implementar busca por prefixo
    // 1 navegar pela Trie seguindo o prefixo
    // 2 coletar todos os jogos na subárvore
    // 3 ordenar resultados
    // 4 retornar até k resultados
    
    return std::vector<Game*>();
}

