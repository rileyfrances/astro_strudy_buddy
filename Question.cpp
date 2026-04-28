#include "Question.h"
#include <iostream>

Question::Question() {

    questionText = "";
    correctAnswer = "";
}

Question::Question(
    std::string text,
    std::string answer
) {

    questionText = text;
    correctAnswer = answer;
}
void Question::display() const {

    std::cout << questionText << std::endl;
}

bool Question::checkAnswer(
    std::string userAnswer
) const {

    return userAnswer == correctAnswer;
}