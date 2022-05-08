#ifndef EX2_Player_H
#define EX2_Player_H
#include "utilities.h"

class Player{
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maxHP of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const char* name,int maxHP, int force);


    /*
     * Copy c'tor of Player class
     *
     * @param p - The player to copy construct from.
     * @return
     *      A copied instance of p.
    */
    Player(const Player& p)=default;


    /*
     * D'tor of Player class
     *
     * @return
     *      Deletes this instance of Player.
    */
    ~Player()=default;


    /*
     * Assignment operator
     *
     * @param p - The player to assign from.
     * @return  
     *      default
    */
    Player& operator=(Player p) =default;


    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo();


    /*
     * Increases the level of the player by one.
     *
     * @return
     *      void
    */
    void levelUp();


    /*
     * Returns the level of the player.
     *
     * @return
     *      The level of the player.
    */
    int getLevel();


    /*
     * Increases the force of the player by given amount.
     *
     * @param forceToAdd - The given amount to add to the force of the player.
     * @return
     *      void
    */
    void buff(int forceToAdd);


    /*
     * Increases the HP of the player by given amount of points.
     *
     * @param printsToHeal - the amount of points to add to the HP of the player.
     * @return
     *      void
    */
    void heal(int pointsToHeal);


    /*
     * Decreases the HP of the player by given amount of points.
     *
     * @param damageToDeal - the amount of points to reduce from the HP of the player.
     * @return
     *      void
    */
    void damage(int damageToDeal);


    /*
     * Check if the player is knocked out:
     *
     * @return
     *      True if player is knocked out
     *      False otherwise
    */
    bool isKnockedOut();


    /*
     * Increases the coins of the player by given amount of coins.
     *
     * @param coinsToAdd - the amount of coins to add to the coins of the player.
     * @return
     *      void
    */
    void addCoins(int coinsToAdd);


    /*
     * Check if player can pay the given amount of coins, and pays if possible.
     *
     * @param coinsToPay - the amount of coins to pay.
     * @return
     *      True if player can pay
     *      False otherwise
    */
    bool pay(int coinsToPay);


    /*
     * Returns the attack strenth, which is defined as force + level of the player.
     *
     * @return
     *      The attack strenth of the player.
    */
    int getAttackStrength();

private:
    char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};


#endif