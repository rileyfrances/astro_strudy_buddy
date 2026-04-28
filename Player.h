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
    int getHealth () const;
    int getScore()const;
};

#endif