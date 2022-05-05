
#include "Player.h"
#define DEFAULT_FORCE 5
#define DEFAULT_MAXHP 100
#define FIRST 1
#define MAX_LEVEL 10


Player::Player( char* name,int maxHP=DEFAULT_MAXHP, int force=DEFAULT_FORCE)
{
    this->m_name= name;
    if(maxHP>=0)
    {
        this->m_maxHP= maxHP;
    }
    else
    {
        this->m_maxHP= DEFAULT_MAXHP;
    }
    if(force>=0)
    {
        this->m_force= force;
    }
    else
    {
        this->m_force= DEFAULT_FORCE;
    }
    this->m_HP= maxHP;
    this->m_level= FIRST;
}

Player::Player(const Player& player)
{
    this->m_name= player.m_name;
    this->m_maxHP= player.m_maxHP;
    this->m_force= player.m_force;
    this->m_coins= player.m_coins;
    this->m_HP= player.m_maxHP;
    this->m_level= player.m_level;
}

Player::~Player()
{

}

Player& Player::operator=(const Player p)
{
    this->m_name= p.m_name;
    this->m_maxHP= p.m_maxHP;
    this->m_force= p.m_force;
    this->m_coins= p.m_coins;
    this->m_HP= p.m_maxHP;
    this->m_level= p.m_level;
    return *this;
}
void Player::printInfo()
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp()
{
    if(this->m_level!= MAX_LEVEL)
    {
        this->m_level++;
    }
}

int Player::getLevel()
{
    return this->m_level;
}

void Player::buff(int forceToAdd)
{
    if(forceToAdd>0)
    {
        this->m_force += forceToAdd;
    } 
}

void Player::heal(int pointsToHeal)
{
    if(pointsToHeal>0)
    {
        if(this->m_HP+ pointsToHeal > this->m_maxHP)
        {
            this->m_HP= this->m_maxHP;
        }
        else
        {
            this->m_HP += pointsToHeal;
        }
    }
}

void Player::damage(int damageToMake)
{
    if(damageToMake>0)
    {
        if(this->m_HP - damageToMake <0)
        {
            this->m_HP =0;
        }
        else
        {
            this->m_HP -= damageToMake;
        }
    }
}

bool Player::isKnockedOut()
{
    if(!(this->m_HP))
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd>0)
    {
        this->m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay)
{
    if(coinsToPay>0)
    {
        if(this->m_coins - coinsToPay <0)
        {
            return false;
        }
        else
        {
            this->m_coins -= coinsToPay;
            return true;
        }
    }
    return true;
}

int Player::getAttackStrength()
{
    return this->m_force + this->m_level;
}






