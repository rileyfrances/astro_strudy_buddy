#include "Question.h"
#include <iostream>
#include <algorithm>  


std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


Question::Question() {
    questionText = "";
    correctAnswer = "";
}

Question::Question(std::string text, std::string answer) {
    questionText = text;
    correctAnswer = answer;
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