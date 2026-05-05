#include "Question.h"
#include <iostream>
#include <algorithm>  // for transform

// ✅ helper function (must be OUTSIDE the class and functions)
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// constructors
Question::Question() {
    questionText = "";
    correctAnswer = "";
}

Question::Question(std::string text, std::string answer) {
    questionText = text;
    correctAnswer = answer;
}

// display
void Question::display() const {
    std::cout << questionText << std::endl;
}

// ✅ FIXED answer checking
bool Question::checkAnswer(std::string userAnswer) const {

    std::string user = toLower(userAnswer);
    std::string correct = toLower(correctAnswer);

    // exact match
    if (user == correct) {
        return true;
    }

    // partial match
    if (correct.find(user) != std::string::npos) {
        return true;
    }

    return false;
}