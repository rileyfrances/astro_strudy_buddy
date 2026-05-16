#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {

private:

    std::string questionText;
    std::string correctAnswer;

public:

    Question();

    Question(
        std::string text,
        std::string answer
    );

    void display() const;

    bool checkAnswer(
        std::string userAnswer
    ) const;

};

#endif