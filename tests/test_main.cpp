#include <cassert>
#include "../src/Player.h"
#include "../src/Question.h"

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
    Question q("Test", "brain");
    assert(q.checkAnswer("brain"));
}
int main() {
    test_damage();
    test_heal();
    test_answer();
    return 0;
}
