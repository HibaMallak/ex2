
#ifndef UNTITLED1_HEALTHPOINTS_H
#define UNTITLED1_HEALTHPOINTS_H

#include <iostream>
using std::cout;
using std::endl;

static const int DEFAULT_MAX_HP= 100;
static const int MIN_HP = 0;

class HealthPoints {
public:
    /*
     * C'tor of HealthPoints class
     *
     * @param maxHP - The maximum HealthPoints of the player.
     * @return
     *      A new instance of HealthPoints.
    */
    HealthPoints(int maxHP = DEFAULT_MAX_HP);


    HealthPoints(const HealthPoints& h)=default;


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

    HealthPoints& operator+=(const int num);
    HealthPoints& operator-=(const int num);

    friend bool operator==(const HealthPoints& first, const HealthPoints& other) ;
    friend bool operator<(const HealthPoints& first, const HealthPoints& other) ;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& first) ;



    class InvalidArgument {};

private:
    int m_maxHealthPoints;
    int m_tempHealthPoints;
    int get_m_tempHealthPoints() const;
    int get_m_maxHealthPoints() const;


};
bool operator!=(const HealthPoints& first, const HealthPoints& other);
bool operator<=(const HealthPoints& first, const HealthPoints& other);
bool operator>(const HealthPoints& first, const HealthPoints& other);
bool operator>=(const HealthPoints& first, const HealthPoints& other);

HealthPoints operator+(const HealthPoints& healthPoints, const int num);
HealthPoints operator+(const int num, const HealthPoints& healthPoints);
HealthPoints operator-(const HealthPoints& healthPoints, const int num);


#endif //UNTITLED1_HEALTHPOINTS_H

