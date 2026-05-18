#include "Question.h"
#include <iostream>
#include <algorithm>
#include <cmath>

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

Question::Question() {
    questionText = "";
    correctAnswer = "";
    hints = {};
}

Question::Question(std::string text, std::string answer, std::string hintText) {
    questionText = text;
    correctAnswer = answer;
    hints = { hintText };
}

Question::Question(std::string text, std::string answer, std::vector<std::string> hintsVec) {
    questionText = text;
    correctAnswer = answer;
    hints = hintsVec;
}

void Question::display() const {
    std::cout << questionText << std::endl;
}

bool Question::checkAnswer(std::string userAnswer) const {

    std::string user = toLower(userAnswer);
    std::string correct = toLower(correctAnswer);

    if (user == correct) {
        return true;
    }

    if (correct.find(user) != std::string::npos) {
        return true;
    }

    return false;
}

std::string Question::getHint() const {
    if (hints.empty()) return "";
    return hints.front();
}

std::string Question::getHintAt(int index) const {
    if (index < 0 || index >= (int)hints.size()) return "";
    return hints[index];
}

std::string Question::revealNextHint() {
    if (hintsRevealed < (int)hints.size()) {
        std::string h = hints[hintsRevealed];
        hintsRevealed++;
        return h;
    }
    return "";
}

void Question::incrementAttempt() {
    attemptCount++;
}

void Question::resetAttempts() {
    attemptCount = 0;
    hintsRevealed = 0;
}

int Question::getAttempts() const {
    return attemptCount;
}

int Question::getHintsRevealed() const {
    return hintsRevealed;
}

bool Question::isMastered() const {
    return mastered;
}

void Question::setMastered(bool val) {
    mastered = val;
}

void Question::setPreviouslyMissed(bool val) {
    previouslyMissed = val;
}

bool Question::wasPreviouslyMissed() const {
    return previouslyMissed;
}