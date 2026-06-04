#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game {
private:
    std::string title;
    std::string shortDescription;
    int popularity;

public:
    Game();
    Game(std::string t, std::string d, int p);
    std::string getTitle();
    std::string getShortDescription();
    int getPopularity();

    ~Game() = default;

    
};

#endif
