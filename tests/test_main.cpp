#include <cassert>
#include <iostream>
#include "../src/Player.h"
#include "../src/Question.h"

void test_question_hint() {
    std::cout << "Question hint test... ";
    Question q(
        "What hormone lowers blood sugar?",
        "insulin",
        "Produced by the pancreas"
    );
    assert(q.getHint() =="Produced by the pancreas");
    std::cout << "PASSED\n";
}
void test_empty_hint() {
    std::cout << "Empty hint test... ";
    Question q(
        "Test Question",
        "brain",
        ""
    );

    assert(q.getHint() == "");
    std::cout << "PASSED\n";
}
void test_reveal_hints_and_attempts() {
    std::cout << "Reveal hints and attempts test... ";
    std::vector<std::string> hints = {"first hint", "second hint"};
    Question q("Q","a", hints);
    assert(q.getHintsRevealed() == 0);
    std::string h1 = q.revealNextHint();
    assert(h1 == "first hint");
    assert(q.getHintsRevealed() == 1);
    std::string h2 = q.revealNextHint();
    assert(h2 == "second hint");
    assert(q.getHintsRevealed() == 2);
    std::string h3 = q.revealNextHint();
    assert(h3 == "");
    assert(q.getAttempts() == 0);
    q.incrementAttempt();
    assert(q.getAttempts() == 1);
    std::cout << "PASSED\n";
}
void test_reward_retry_health_limit() {
    std::cout << "Retry reward health limit test... ";
    Player p;
    p.rewardRetrySuccess();
    assert(p.getHealth() == 100);
    std::cout << "PASSED\n";
}

void test_damage() {
    Player p;
    p.takeDamage(20);
    assert(p.getHealth() == 80);
}
void test_heal() {
    Player p;
    p.takeDamage(50);
    p.gainHealth(20);
    assert(p.getHealth() == 70);
}
void test_answer() {
    Question q("Test","brain","Controls thinking");
    assert(q.checkAnswer("brain"));
}

void test_choices_api_and_check() {
    std::cout << "Multiple-choice API and check test... ";
    Question q(
        "What part of the brain coordinates voluntary movements?",
        "cerebellum",
        "Located at the back of the skull"
    );
    std::vector<std::string> choices = {"cerebrum", "cerebellum", "brainstem"};
    q.setChoices(choices);
    q.setMultipleChoice(true);
    assert(q.isMultipleChoice());
    auto got = q.getChoices();
    assert(got.size() == 3);
    // check by text
    assert(q.checkAnswer("cerebellum"));
    // check by numeric selection (1-based)
    assert(q.checkAnswer("2"));
    std::cout << "PASSED\n";
}
int main() {
    test_damage();
    test_heal();
    test_answer();
    test_question_hint();
    test_empty_hint();
    test_reveal_hints_and_attempts();
    test_reward_retry_health_limit();
    test_choices_api_and_check();

    std::cout << "\nAll tests passed!\n";

    return 0;
}
