
#include "Player.h"
#define DEFAULT_FORCE 5
#define DEFAULT_MAXHP 100
#define FIRST 1
#define MAX_LEVEL 10
#define COINS_IN_START 0


Player::Player(const char* name,int maxHP=DEFAULT_MAXHP, int force=DEFAULT_FORCE) : m_name(name), m_level(FIRST),
               m_force(force), m_maxHP(maxHP), m_HP(maxHP), m_coins(COINS_IN_START)
{
    if(maxHP<=0)
    {
        this->m_maxHP= DEFAULT_MAXHP;
        this->m_HP= DEFAULT_MAXHP;
    }

    if(force<=0)
    {
        this->m_force= DEFAULT_FORCE;
    }

}


void Player::printInfo()
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp()
{
    if(this->m_level!= MAX_LEVEL)
    {
        ++this->m_level;
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
    if(this->m_HP <=0)
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
    if(coinsToPay>=0)
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
    return false;
}

int Player::getAttackStrength()
{
    return this->m_force + this->m_level;
}








