#ifndef LEVEL_H
#define LEVEL_H

#include "Question.h"

class Level {

private:

    Question questions[10];

    int totalQuestions;
    int currentQuestion;

public:

    Level();

    void addQuestion(Question q);
    Question getCurrentQuestion();
    bool hasMoreQuestions() const;
    void nextQuestion();

};

#endif