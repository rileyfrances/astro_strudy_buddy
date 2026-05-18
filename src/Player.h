#ifndef PLAYER_H
#define PLAYER_H

class Player{

private:

    int health;
    int maxHealth;
    int attackPower;
    int score;

public:
    Player();

    void takeDamage(int amount);
    void gainHealth(int amount);
    void addScore(int points);
    void increaseAttackPower(int amount);
    void rewardRetrySuccess();
    int getHealth() const;
    int getScore() const;
    int getAttackPower() const;
    void resetPlayer();
    bool isAlive() const;
};

#endif