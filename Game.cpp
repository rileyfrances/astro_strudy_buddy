#include "Game.h"
#include <iostream>
#include <string>

Game::Game() {
    running = true;
    currentLevel = 0;

    setupLevels();
}

void Game::setupLevels() {


    Level level1;

    level1.addQuestion(Question(
        "What part of the brain coordinates voluntary movements?",
        "cerebellum"
    ));

    level1.addQuestion(Question(
        "What part of the brain handles memory and reasoning?",
        "cerebrum"
    ));

    level1.addQuestion(Question(
        "What system triggers fight or flight responses?",
        "sympathetic nervous system"
    ));


    Level level2;

    level2.addQuestion(Question(
        "What hormone lowers blood sugar?",
        "insulin"
    ));

    level2.addQuestion(Question(
        "What hormone raises blood sugar?",
        "glucagon"
    ));

    level2.addQuestion(Question(
        "Which organ creates bile?",
        "liver"
    ));


    Level bossLevel;

    bossLevel.addQuestion(Question(
        "What are the receptor cells in hearing?",
        "hair cells"
    ));

    bossLevel.addQuestion(Question(
        "Which portion of the neuron receives signals?",
        "dendrites"
    ));

    bossLevel.addQuestion(Question(
        "What organ releases digestive enzymes?",
        "pancreas"
    ));


    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(bossLevel);
}

void Game::showLevelStory() {

    if (currentLevel == 0) {
        std::cout << "\n----LEVEL 1----\n";
        std::cout << "\nYour ship enters deep space.\n";
        std::cout << "\nAnswer questions to stabilize navigation.\n";
    }

    else if (currentLevel == 1) {
        std::cout << "\n----LEVEL 2----\n";
        std::cout << "\nA strange alien planet appears.\n";
        std::cout << "\nUse your medical knowledge to survive.\n";
    }

    else if (currentLevel == 2) {
        std::cout << "\n----FINAL BOSS----\n";
        std::cout << "\nThe final system failure begins.\n";
        std::cout << "\nMaster all concepts to save humanity.\n";
    }
}

void Game::run() {

    std::cout << "\nWelcome to AstroStudy Buddy!\n";

    while (running && currentLevel < levels.size()) {
        showLevelStory();
        Level& level = levels[currentLevel];

        while (level.hasMoreQuestions()) {
            processQuestion();
            if (player.getHealth() <= 0) {
                std::cout << "You lost all health!";
                running = false;
                break;
            }
        }

        if (!running) {
            break;
        }
        if (level.hasIncorrectQuestions()) {
            std::cout << "Retrying missed questions...";
            level.retryIncorrect();
        }

        else {
            std::cout << "LEVEL COMPLETE!";
            player.addScore(50);
            player.increaseAttackPower(5);
            std::cout << "Attack Power Increased!";
            currentLevel++;
        }
    }


    if (player.getHealth() > 0) {
        std::cout << "You completed AstroStudy Buddy!";
        std::cout << "Final Score: " << player.getScore() << std::endl;
    }

    else {
        std::cout << "Game Over.";
    }
}

void Game::processQuestion() {
    Level& level = levels[currentLevel];
    Question q = level.getCurrentQuestion();
    q.display();
    std::string answer;
    std::getline(std::cin >> std::ws, answer);

    if (q.checkAnswer(answer)) {
        std::cout << "Correct!";
        player.addScore(10);
    }

    else {
        std::cout << "Wrong! Lose health.";
        player.takeDamage(10);
        level.addIncorrectQuestion(q);
    }

    level.nextQuestion();

    std::cout << "Health: "<< player.getHealth()<< std::endl;
    std::cout << "Score: "<< player.getScore()<< std::endl;
}