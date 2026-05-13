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
        "sympathetic"
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
        std::cout << "----LEVEL 1----";
        std::cout << "Your ship enters deep space.";
        std::cout << "Answer questions to stabilize navigation.";
    }

    else if (currentLevel == 1) {
        std::cout << "----LEVEL 2----";
        std::cout << "A strange alien planet appears.";
        std::cout << "Use your medical knowledge to survive.";
    }

    else if (currentLevel == 2) {
        std::cout << "----FINAL BOSS----";
        std::cout << "The final system failure begins.";
        std::cout << "Master all concepts to save humanity.";
    }
}

void Game::run() {

    std::cout << "Welcome to AstroStudy Buddy! ";

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