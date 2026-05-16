#ifndef LEVEL_H
#define LEVEL_H

#include "Question.h"
#include <vector>

class Level {
private:
    std::vector<Question> questions;
    std::vector<Question> incorrectQuestions;
    int currentQuestion;

public:
    Level();
    void addQuestion(Question q);
    Question getCurrentQuestion();
    bool hasMoreQuestions() const;
    void nextQuestion();
    void addIncorrectQuestion(Question q);
    bool hasIncorrectQuestions() const;
    void retryIncorrect();
    Question getCurrentQuestion() const;
};
#endif