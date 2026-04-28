#include "Game.h"
#include <iostream>

Game::Game() {

    running = true;

    setupQuestions();
}
void Game::setupQuestions() {

    level.addQuestion(
        Question()
    );
}
void Game::run() {

    std::cout << "Welcome to AstroStudy Buddy!";

    while (
        running &&level.hasMoreQuestions()
    ) {

        processQuestion();
        if (player.getHealth() <= 0) {

            std::cout<< "You ran out of health!";

            running = false;
        }
    }
    std::cout << "Game Over!";
}

void Game::processQuestion() {

    Question q =level.getCurrentQuestion();
    q.display();

    std::string answer;

    std::cin >> answer;
    if (q.checkAnswer(answer)) {

        std::cout<< "Correct!";
        player.addScore(10);
        level.nextQuestion();

    }else {
        std::cout<< "Wrong! Lose health.";
        player.takeDamage(10);
    }
    std::cout<< "Health: "<< player.getHealth()<< std::endl;

}


   