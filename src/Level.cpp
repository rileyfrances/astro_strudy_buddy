#include "Level.h"

Level::Level() {
    currentQuestion = 0;
}

void Level::addQuestion(Question q) {
    questions.push_back(q);
}

Question Level::getCurrentQuestion() {
    return questions[currentQuestion];
}

bool Level::hasMoreQuestions() const {
    return currentQuestion < questions.size();
}

void Level::nextQuestion() {
    currentQuestion++;
}


void Level::addIncorrectQuestion(Question q) {
    incorrectQuestions.push_back(q);
}

bool Level::hasIncorrectQuestions() const {
    return !incorrectQuestions.empty();
}

void Level::retryIncorrect() {
    questions = incorrectQuestions;
    incorrectQuestions.clear();
    currentQuestion = 0;
}
Question Level::getCurrentQuestion() const {
    return questions[currentQuestion];
}