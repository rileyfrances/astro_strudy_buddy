#include "Player.h"

Player::Player(){
    maxHealth = 100;
    health = 100;
    attackPower = 10;
    score = 0;
}
void Player::takeDamage(int amount){
    health-=amount;
    if (health<0){
        health=0;
    }
}
void Player::gainHealth(int amount){
    health += amount;
    if (health>maxHealth){
        health=maxHealth;
    }
}
void Player::addScore(int points){
    score+=points;
}
int Player::getHealth()const {
    return health;
}
int Player::getScore()const{
    return score;
}