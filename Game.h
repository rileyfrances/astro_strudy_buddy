#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Level.h"
#include <vector>

class Game {
private:
    Player player;

    std::vector<Level> levels;
    int currentLevel;
    bool running;
    void processQuestion();
    void setupLevels();
    void showLevelStory();

public:
    Game();
    void run();
};

#endif