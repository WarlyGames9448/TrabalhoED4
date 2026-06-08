#include "Trie.hpp"

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

bool Trie::isBefore(Game* a, Game* b) {
    if (a->getPopularity() != b->getPopularity()) {
        return a->getPopularity() > b->getPopularity();
    }
    return toSearchKey(a->getTitle()) < toSearchKey(b->getTitle());
}

int Trie::Partition(std::vector<Game*>& games, int low, int high){
    Game* pivot = games[low];

    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && isBefore(games[left], pivot)) {
            left++;
        }

        while (left <= right && isBefore(pivot, games[right])) {
            right--;
        }

        if (left > right) {
            break;
        }

        Game* aux = games[left];
        games[left] = games[right];
        games[right] = aux;
    }

    Game* aux = games[low];
    games[low] = games[right];
    games[right] = aux;

    return right;
}

void Trie::QuickSort(std::vector<Game*>& games, int low, int high){
    if (low < high) {
        int pi = Partition(games, low, high);

        QuickSort(games, low, pi - 1);
        QuickSort(games, pi + 1, high);
    }
}

void Trie::sortResults(std::vector<Game*>& games) {
    if(!games.empty()){
        QuickSort(games, 0, games.size() - 1);
    }
}

void Trie::searchGames(TrieNode* node, std::vector<Game*>& foundGames){
    if(node->isEndOfTitle)
        foundGames.push_back(node->game);

    for (int index=0; index<ALPHABET_SIZE; index++){
        if(node->children[index])
            searchGames(node->children[index], foundGames);
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {
    std::vector<Game*> foundGames;

    TrieNode* node = root;

    if(k <= 0) return foundGames; //empty

    std::string key = toSearchKey(prefix);

    for(char c: key){
        int index = getCharIndex(c);

        if(node->children[index] == nullptr){
            return foundGames; //empty
        }

        node = node->children[index];
    }

    searchGames(node, foundGames);

    sortResults(foundGames);

    int limit = std::min(k, (int)foundGames.size());
    std::vector<Game*> subvector(foundGames.begin(), foundGames.begin() + limit);
    return subvector;
}

