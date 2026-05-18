# Question Hints — Spec

## Problem Statement
Players can receive hints after incorrect answers and earn bonus rewards when retrying missed questions.

## Types Involved
- Question
- Level
- Player
- Game

## Public Interface

### Question

Question(std::string text,std::string answer,std::string hint);

std::string getHint() const;

### Player

void rewardRetrySuccess();

## Inputs and Outputs

Input:
- player enters answers

Output:
- hints displayed after wrong answers
- retry reward message shown

## Edge Cases
1. Empty hint
2. Health exceeding max health
3. Multiple retries
4. Correct answer on first try

## Three Tests

1. Normal:
Player gets a hint after wrong answer.

2. Edge:
Question has empty hint.

3. Boundary:
Health reward cannot exceed max health.

## Design Decisions
Used a simple string hint field instead of creating another class