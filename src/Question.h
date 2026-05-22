#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {

private:
    std::string questionText;
    std::string correctAnswer;
    std::vector<std::string> hints;
    std::vector<std::string> choices;
    bool multipleChoice = false;

    int attemptCount = 0;
    int hintsRevealed = 0;
    bool mastered = false;
    bool previouslyMissed = false;

public:

    Question();
    Question(std::string text, std::string answer, std::string hint);
    Question(std::string text, std::string answer, std::vector<std::string> hintsVec);

    void display() const;

    bool checkAnswer(std::string userAnswer) const;

    std::string getHint() const;

    std::string getHintAt(int index) const;
    std::string revealNextHint(); 
    void incrementAttempt();
    void resetAttempts();
    int getAttempts() const;
    int getHintsRevealed() const;
    bool isMastered() const;
    void setMastered(bool val);
    void setPreviouslyMissed(bool val);
    bool wasPreviouslyMissed() const;

    // Multiple-choice support
    std::vector<std::string> getChoices() const;
    void setChoices(const std::vector<std::string>& c);
    bool isMultipleChoice() const;
    void setMultipleChoice(bool val);
};

#endif