#include "Game.h"
#include <iostream>
#include <string>
#include <cmath>

const int BASE_REWARD = 100;
const double RETRY_MULTIPLIERS[] = {1.0, 0.7, 0.4, 0.1};
const double HINT_PENALTY_PER_HINT = 0.10; 
const double MASTERY_BONUS = 0.25; 
const int HINT_HEALTH_COST = 1;
const int MAX_RETRIES = 5;

static int calculateReward(int base, int attempts, int hintsRevealed, bool previouslyMissed) {
    double multiplier = 0.1;
    int len = sizeof(RETRY_MULTIPLIERS)/sizeof(RETRY_MULTIPLIERS[0]);
    if (attempts < len) {
        multiplier = RETRY_MULTIPLIERS[attempts];
    } else {
        multiplier = RETRY_MULTIPLIERS[len - 1];
    }
    double hintPenalty = HINT_PENALTY_PER_HINT * hintsRevealed;
    if (hintPenalty > 0.8) hintPenalty = 0.8; 
    double reward = base * multiplier * (1.0 - hintPenalty);
    if (previouslyMissed) reward *= (1.0 + MASTERY_BONUS);
    int r = (int)std::round(reward);
    if (r < 0) r = 0;
    return r;
}

Game::Game() {
    running = true;
    currentLevel = 0;

    setupLevels();
}

void Game::setupLevels() {


    Level level1;

    level1.addQuestion(Question(
        "What part of the brain coordinates voluntary movements?",
        "cerebellum",
        "Located at the back of the skull, beneath the main part of the brain"
    ));

    level1.addQuestion(Question(
        "What part of the brain handles memory and reasoning?",
        "cerebrum",
        "The largest part of the brain"
    ));

    level1.addQuestion(Question(
        "What system triggers fight or flight responses?",
        "sympathetic nervous system",
        "Controls involuntary, automatic bodily functions"
    ));


    Level level2;

    level2.addQuestion(Question(
        "What hormone lowers blood sugar?",
        "insulin",
        "Produced by Pancreas"
    ));

    level2.addQuestion(Question(
        "What hormone raises blood sugar?",
        "glucagon",
        "Produced by Pancreas"
    ));

    level2.addQuestion(Question(
        "Which organ creates bile?",
        "liver",
        "The body's largest internal organ"
    ));


    Level bossLevel;

    bossLevel.addQuestion(Question(
        "What are the receptor cells in hearing?",
        "hair cells",
        "Translates fluid vibrations caused by sound into electrical signals."
    ));

    bossLevel.addQuestion(Question(
        "Which portion of the neuron receives signals?",
        "dendrites",
        "branched, tree-like projections extending outward from the cell body (soma) of a neuron."
    ));

    bossLevel.addQuestion(Question(
        "What organ releases digestive enzymes?",
        "pancreas",
        "Aiding in digestion and regulating your blood sugar"
    ));


    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(bossLevel);
}

void Game::showLevelStory() {

    if (currentLevel == 0) {
        std::cout << "\n\n---- LEVEL 1 ----\n\n";
        std::cout << "Your ship enters deep space." << std::endl;
        std::cout << "Answer questions to stabilize navigation." << std::endl;
        std::cout << std::endl;
    }

    else if (currentLevel == 1) {
        std::cout << "\n\n---- LEVEL 2 ----\n\n";
        std::cout << "A strange alien planet appears." << std::endl;
        std::cout << "Use your medical knowledge to survive." << std::endl;
        std::cout << std::endl;
    }

    else if (currentLevel == 2) {
        std::cout << "\n\n---- FINAL BOSS ----\n\n";
        std::cout << "The final system failure begins." << std::endl;
        std::cout << "Master all concepts to save humanity." << std::endl;
        std::cout << std::endl;
    }
}

void Game::run() {

    std::cout << "\n\nWelcome to AstroStudy Buddy!\n\n";

    while (running && currentLevel < levels.size()) {
        showLevelStory();
        Level& level = levels[currentLevel];

        while (level.hasMoreQuestions()) {
            processQuestion();
            if (player.getHealth() <= 0) {
                std::cout << "\nYou lost all health!\n";
                running = false;
                break;
            }
        }

        if (!running) {
            break;
        }
        if (level.hasIncorrectQuestions()) {
            std::cout << "\nRetrying missed questions...\n\n";
            level.retryIncorrect();
            player.rewardRetrySuccess();
            std::cout << "Retry reward earned!" << std::endl;
            std::cout << std::endl;
        }

        else {
            std::cout << "\nLEVEL COMPLETE!" << std::endl;
            player.addScore(50);
            player.increaseAttackPower(5);
            std::cout << "Attack Power Increased!" << std::endl;
            std::cout << std::endl;
            currentLevel++;
        }
    }


    if (player.getHealth() > 0) {
        std::cout << "\nYou completed AstroStudy Buddy!" << std::endl;
        std::cout << "Final Score: " << player.getScore() << std::endl;
    }

    else {
        std::cout << "\nGame Over." << std::endl;
    }
}

void Game::processQuestion() {
    Level& level = levels[currentLevel];
    Question q = level.getCurrentQuestion();

    std::cout << std::endl;
    q.display();
    std::cout << std::endl;

    bool inRetry = (q.getAttempts() > 0) || q.wasPreviouslyMissed();
    if (inRetry) {
        std::cout << "(This question is a retry) Request a hint? (y/n): ";
        std::string hintChoice;
        std::getline(std::cin >> std::ws, hintChoice);
        if (!hintChoice.empty() && (hintChoice[0] == 'y' || hintChoice[0] == 'Y')) {
            std::string hintText = q.revealNextHint();
            if (!hintText.empty()) {
                std::cout << "\nHint: " << hintText << std::endl;
                player.takeDamage(HINT_HEALTH_COST);
            } else {
                std::cout << "\nNo more hints available." << std::endl;
            }
            std::cout << std::endl;
        }
    }

    std::string answer;
    std::getline(std::cin >> std::ws, answer);

    if (q.checkAnswer(answer)) {
        if (inRetry) {
            // reward for retry/correct
            int attempts = q.getAttempts();
            int hintsUsed = q.getHintsRevealed();
            int reward = calculateReward(BASE_REWARD, attempts, hintsUsed, q.wasPreviouslyMissed());
            player.addScore(reward);
            // small health restore on mastery
            if (q.wasPreviouslyMissed() && !q.isMastered()) {
                player.gainHealth(5);
            }
            q.setMastered(true);
            q.resetAttempts();
            q.setPreviouslyMissed(false);
            std::cout << "\nCorrect (retry)! Reward: " << reward << std::endl;
        } else {
            std::cout << "\nCorrect!" << std::endl;
            player.addScore(10);
        }
    } else {
        std::cout << "\nWrong! Lose health." << std::endl;
        player.takeDamage(10);

        std::cout << "Hint: " << q.getHint() << std::endl;

        q.incrementAttempt();
        q.setPreviouslyMissed(true);

        if (q.getAttempts() < MAX_RETRIES) {
            level.addIncorrectQuestion(q);
        } else {
            std::cout << "Max retries reached for this question; skipping further retries." << std::endl;
        }
    }

    level.nextQuestion();

    std::cout << "\nHealth: "<< player.getHealth()<< std::endl;
    std::cout << "Score: "<< player.getScore()<< std::endl;
    std::cout << std::endl;
}