#include "Level.h"

Level::Level() {

    totalQuestions = 0;
    currentQuestion = 0;
}
void Level::addQuestion(Question q) {

    questions[totalQuestions] = q;

    totalQuestions++;
}

Question Level::getCurrentQuestion() {

    return questions[currentQuestion];
}

bool Level::hasMoreQuestions() const {

    return currentQuestion < totalQuestions;
}

void Level::nextQuestion() {

    currentQuestion++;
}