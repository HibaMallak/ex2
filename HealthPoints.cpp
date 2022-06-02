#include "HealthPoints.h"
#include <iostream>
using std::cout;
using std::endl;


HealthPoints:: HealthPoints(int maxHP)
{
    /* InvalidArgument exception is thrown if the recieved maxHP is smaller or equal to zero.*/
    if(maxHP <= MIN_HP)
    {
        throw HealthPoints::InvalidArgument();
    }
    m_maxHealthPoints=maxHP;
    m_cuurentHP=maxHP;

}

HealthPoints& HealthPoints::operator=(HealthPoints h)
{
    this->m_cuurentHP= h.get_m_currentHP();
    this->m_maxHealthPoints= h.get_m_maxHealthPoints();

    return *this;
}

int HealthPoints::get_m_currentHP() const
{
    return this->m_cuurentHP;
}

int HealthPoints::get_m_maxHealthPoints() const
{
    return this->m_maxHealthPoints;
}

HealthPoints& HealthPoints:: operator+=(const int num)
{
    m_cuurentHP = m_cuurentHP + num;

    if (m_cuurentHP > m_maxHealthPoints)
    {
        m_cuurentHP = m_maxHealthPoints;
    }

    if (m_cuurentHP < MIN_HP)
    {
        m_cuurentHP = MIN_HP;
    }

    return *this;

}
HealthPoints& HealthPoints:: operator-=(const int num)
{
    return *this += -num;
}

HealthPoints operator+(const HealthPoints& healthPoints, const int num)
{
    return HealthPoints(healthPoints) += num;
}

HealthPoints operator+(const int num, const HealthPoints& healthPoints)
{
    return HealthPoints(healthPoints) += num;
}

HealthPoints operator-(const HealthPoints& healthPoints, const int num)
{
    return HealthPoints(healthPoints) -= num;
}

bool operator==(const HealthPoints& first, const HealthPoints& other)
{
    return first.get_m_currentHP()== other.get_m_currentHP();
}

bool operator!=(const HealthPoints& first, const HealthPoints& other)
{
    return !(first == other);
}

bool operator<(const HealthPoints& first, const HealthPoints& other)
{
    return (first.get_m_currentHP() < other.get_m_currentHP());

}

bool operator<=(const HealthPoints& first, const HealthPoints& other)
{
    return !(other < first);
}

bool operator>(const HealthPoints& first, const HealthPoints& other)
{
    return (other < first);
}

bool operator>=(const HealthPoints& first, const HealthPoints& other)
{
    return other <= first;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& first)
{
    return os << first.get_m_currentHP() << "(" << first.get_m_maxHealthPoints() << ")"  ;
}

