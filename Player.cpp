#include "Player.h"



Player::Player( char* name,int maxHP=100, int force=5)
{
    this->name= name;
    this->maxHP= maxHP;
    this->force= force;
    this->coins=0;
    this->HP= maxHP;
    this->level=0;
}

Player::Player(const Player& player)
{
    this->name= player.name;
    this->maxHP= player.maxHP;
    this->force= player.force;
    this->coins= player.coins;
    this->HP= player.maxHP;
    this->level= player.level;
}

Player::~Player()
{

}