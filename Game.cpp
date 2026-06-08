#include "Game.hpp"

Game::Game() {
    title = "";
    shortDescription = "";
    popularity = 0;
}

Game::Game(std::string t, std::string d, int p) {
    this->title = t;
    this->shortDescription = d;
    this->popularity = p;
}

Game::~Game() {}

std::string Game::getTitle() {
    return title;
}

std::string Game::getShortDescription() {
    return shortDescription;
}

int Game::getPopularity() {
    return popularity;
}