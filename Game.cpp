#include "Game.h"
#include <iostream>
#include <string>   
Game::Game() {
    running = true;
    setupQuestions();
}

void Game::setupQuestions() {

    level.addQuestion(Question(
        "A plane that separates the human body  into upper and lower parts is called a",
        "transverse plane"
    ));

    level.addQuestion(Question(
        "A plane that separates the human body into a front (anterior) and back (posterior) part is called a",
        "frontal plane"
    ));

    level.addQuestion(Question(
        "What part of the brain coordinates voluntary movements, balance, and posture?",
        "cerebellum"
    ));
    level.addQuestion(Question(
        "A plane that separates the human body into right and left parts down the bodys midline is called a:",
        "Midsagittal plane"
    ));

    level.addQuestion(Question(
        "What part of the brain handles conscious thought, reasoning, and memory?",
        "cerebrum"
    ));

    level.addQuestion(Question(
        "What part of the peripheral nervous system controls skeletal muscles?",
        "somatic system"
    ));

    level.addQuestion(Question(
        "What part of the peripheral nervous system controls smooth and cardiac muscle?",
        "autonomic system"
    ));

    level.addQuestion(Question(
        "What system triggers fight or flight responses?",
        "sympathetic"
    ));

    level.addQuestion(Question(
        "What are the receptor cells in olfaction?",
        "bipolar olfactory neurons"
    ));

    level.addQuestion(Question(
        "What are the receptor cells in gustation?",
        "taste buds"
    ));

    level.addQuestion(Question(
        "What are the receptor cells in hearing?",
        "hair cells"
    ));

    level.addQuestion(Question(
        "What hormone lowers blood sugar and is produced by beta cells?",
        "insulin"
    ));

    level.addQuestion(Question(
        "What hormone raises blood sugar and is produced by alpha cells?",
        "glucagon"
    ));
    level.addQuestion(Question(
        "Which of the following macromolecules is broken down by pepsin in the stomach?",
        "Proteins"
    ));
     level.addQuestion(Question(
        "Which organ is responsible for creating bile?",
        "Liver"
    ));
    level.addQuestion(Question(
        "What organ releases digestive enzymes into the duodenum?",
        "Pancreas"
    ));
    level.addQuestion(Question(
        "Which portion of the neuron receives electrical signals from other neurons?",
        "Dendrites"
    ));
    level.addQuestion(Question(
        "Which of the following ions causes the release of neurotransmitters into the synaptic cleft?",
        "Calcium ions"
    ));
}

void Game::run() {

    std::cout << "Welcome to AstroStudy Buddy!";

    while (running) {

        while (level.hasMoreQuestions()) {

            processQuestion();

            if (player.getHealth() <= 0) {
                std::cout << "You ran out of health!";
                running = false;
                break;
            }
        }

        if (running && level.hasIncorrectQuestions()) {
            std::cout << "Retrying missed questions...";
            level.retryIncorrect();
        } else {
            break;  
        }
    }

    
    if (player.getHealth() > 0) {
        std::cout << "You mastered all questions! ";
    } else {
        std::cout << "Game Over.";
    }
}

void Game::processQuestion() {

    Question q = level.getCurrentQuestion();
    q.display();

    std::string answer;
    std::getline(std::cin >> std::ws, answer);

    if (q.checkAnswer(answer)) {
        std::cout << "Correct!";
        player.addScore(10);
    } else {
        std::cout << "Wrong! Lose health.";
        player.takeDamage(10);

        level.addIncorrectQuestion(q);  
    }

    level.nextQuestion();  

    std::cout << "Health: " << player.getHealth() << std::endl;
}