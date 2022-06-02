#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <iostream>
using std::cout;
using std::endl;

static const int DEFAULT_MAX_HP = 100;
static const int MIN_HP = 0;

class HealthPoints
{
public:

    /*
     * C'tor of HealthPoints class
     *
     * @param maxHP - The maximum HealthPoints of the player.
     * @return
     *      A new instance of HealthPoints.
    */
    HealthPoints(int maxHP = DEFAULT_MAX_HP);


    /*
     * Copy c'tor of Player class
     *
     * @param h - A reference of an existing HealthPoints instance.
     * @return
     *      A copied instance of h.
    */
    HealthPoints(const HealthPoints& h) = default;


    /* 
     * D'tor of HealthPoints class
     *
     * @return
     *      Deletes this instance of HealthPoints.
    */
    ~HealthPoints()=default;


    /*
     * Assignment operator
     *
     * @param h - The HealthPoints to assign from.
     * @return
     *      default
    */
    HealthPoints& operator=(HealthPoints h);


    /*
     * adds num to the currentHP and returns the new currentHP.
     *
     * @param num - The number of health points to add to the currentHP.
     * 
     * @return
     *      currentHP after adding num.
    */
    HealthPoints& operator+=(const int num);


    /*
     * substracts num from the currentHP and returns the new currentHP.
     *
     * @param num - The number of health points to substract from the currentHP.
     * 
     * @return
     *      currentHP after substracting num.
    */
    HealthPoints& operator-=(const int num);

    /*
     * Compares between the currentHP of two given instances of HealthPoints.
     *
     * @param first - An instance of HealthPoints.
     * @param other - An instance of HealthPoints.
     * @return
     *      True if the currentHP of the two instances is the same.
     *      False otherwise
    */
    friend bool operator==(const HealthPoints& first, const HealthPoints& other);


    /*
     * Compares between the currentHP of two given instances of HealthPoints.
     *
     * @param first - An instance of HealthPoints.
     * @param other - An instance of HealthPoints.
     * @return
     *      True if the currentHP of the other instance's currentHP is bigger than the first's.
     *      False otherwise
    */
    friend bool operator<(const HealthPoints& first, const HealthPoints& other);


    /*
     * Prints the values of currentHP and maxHealthPoints to a given file.
     *
     * @param os - the file to print to.
     * @param first - An instance of HealthPoints.
     * @return
     *      A print.
    */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& first);


    /* 
     * This exception will be thrown 
     * if an invalid argument is received in the constructor of HealthPoints.
    */
    class InvalidArgument {};

private:

    int m_maxHealthPoints;
    int m_cuurentHP;

    /*
     * Returns the currentHP of the HealthPoints instance.
     *
     * @return
     *      The maxHealthPoints.
    */
    int get_m_currentHP() const;

    /*
     * Returns the maxHealthPoints of the HealthPoints instance.
     *
     * @return
     *      The maxHealthPoints.
    */
    int get_m_maxHealthPoints() const;

};


/*
 * Compares between the currentHP of two given instances of HealthPoints.
 *
 * @param first - An instance of HealthPoints.
 * @param other - An instance of HealthPoints.
 * @return
 *      True if the currentHP of the two instances is different.
 *      False otherwise
*/
bool operator!=(const HealthPoints& first, const HealthPoints& other);


/*
 * Compares between the currentHP of two given instances of HealthPoints.
 *
 * @param first - An instance of HealthPoints.
 * @param other - An instance of HealthPoints.
 * @return
 *      True if the currentHP of the other instance's currentHP is bigger than or equal to the first's.
 *      False otherwise
*/
bool operator<=(const HealthPoints& first, const HealthPoints& other);


/*
 * Compares between the currentHP of two given instances of HealthPoints.
 *
 * @param first - An instance of HealthPoints.
 * @param other - An instance of HealthPoints.
 * @return
 *      True if the currentHP of the first instance's currentHP is bigger than the other's.
 *      False otherwise
*/
bool operator>(const HealthPoints& first, const HealthPoints& other);


/*
 * Compares between the currentHP of two given instances of HealthPoints.
 *
 * @param first - An instance of HealthPoints.
 * @param other - An instance of HealthPoints.
 * @return
 *      True if the currentHP of the first instance's currentHP is bigger than or equal to the other's.
 *      False otherwise
*/
bool operator>=(const HealthPoints& first, const HealthPoints& other);


/*
 * adds a given num to the currentHP of a given HealthPoints instance.
 *
 * @param healthPoints - The HealthPoints instance to add the given num to.
 * @param num - The number of health points to add to the currentHP of the given healthPoints.
 * 
 * @return
 *      The healthPoints instance after the adding.
*/
HealthPoints operator+(const HealthPoints& healthPoints, const int num);


/*
 * adds a given number to the currentHP of a given HealthPoints instance.
 *
 * @param healthPoints - The HealthPoints instance to add the given number to.
 * @param num - The number of health points to add to the currentHP of the given healthPoints.
 * 
 * @return
 *      The healthPoints instance after the adding.
*/
HealthPoints operator+(const int num, const HealthPoints& healthPoints);


/*
 * subtracts a given number from the currentHP of a given HealthPoints instance.
 *
 * @param healthPoints - The HealthPoints instance to subtract the given num from.
 * @param num - The number of health points to subtract from the currentHP of the given healthPoints.
 * 
 * @return
 *      The healthPoints instance after the subtracting.
*/
HealthPoints operator-(const HealthPoints& healthPoints, const int num);


#endif