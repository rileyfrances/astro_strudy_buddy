#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Level.h"

class Game {

private:

    Player player;

    Level level;

    bool running;

    void processQuestion();

    void setupQuestions();
public:

    Game();

    void run();
};
#endif