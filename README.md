# astro_strudy_buddy
## Current Status

Project description:
Astro Study Buddy is an educational quiz game focused on reinforcement learning. Players answer study questions, receive hints after incorrect attempts, retry missed questions.

Implemented:
Multi level gameplay system
Health and score tracking
Hint system for incorrect answers
Retry rounds for missed questions
Retry reward system
Multiple choice learning rounds
Typed answer mastery rounds

Stubbed / Planned:
Saving progress between runs
Random question selection
Statistics tracking

Build Instructions:
cmake -S . -B build
cmake --build build

Run Instructions:
./build/game

Test Instructions:
ctest --test-dir build --output-on-failure

Project Structure:
src/Question.*
Stores question data, hints, answer checking, and multiple-choice settings.
src/Player.*
Manages health, score, and gameplay rewards.
src/Level.*
Handles question pools and retry rounds.
src/Game.*
Controls gameplay flow, mastery rounds, and user interaction.
tests/test_main.cpp
Unit tests for gameplay systems and feature behavior.

AI Use:
AI assistance was used for implementation guidance for my hints feature and my multiple choice feature. AI interaction logs are documented in ai_collaboration.md.

Author:
Created by Riley Sullivan-Cross for CIS 25.
