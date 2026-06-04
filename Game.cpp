#include "Game.hpp"

Game();
Game(std::string t, std::string d, int p) {
    this->title = t;
    this->shortDescription = d;
    this->popularity = p;
}
std::string Game::getTitle() const {
    return title;
}
std::string Game::getShortDescription() const {
    return shortDescription;
}
int Game::getPopularity() const {
    return popularity;
}