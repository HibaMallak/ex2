#include "HealthPoints.h"
#include <iostream>
using std::cout;
using std::endl;

HealthPoints:: HealthPoints(int maxHP) :
m_maxHealthPoints(maxHP), m_tempHealthPoints(m_maxHealthPoints)
{
    if(maxHP <= MIN_HP)
    {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator=(HealthPoints h)
{
    this->m_tempHealthPoints= h.get_m_tempHealthPoints();
    return *this;
}

int HealthPoints::get_m_tempHealthPoints() const
{
    return this->m_tempHealthPoints;
}

int HealthPoints::get_m_maxHealthPoints() const
{
    return this->m_maxHealthPoints;
}

HealthPoints& HealthPoints:: operator+=(const int num)
{
    m_tempHealthPoints = m_tempHealthPoints + num;

    if (m_tempHealthPoints > m_maxHealthPoints)
    {
        m_tempHealthPoints= m_maxHealthPoints;
    }

    if (m_tempHealthPoints < MIN_HP)
    {
        m_tempHealthPoints = MIN_HP;
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
    return first.get_m_tempHealthPoints()== other.get_m_tempHealthPoints();
}

bool operator!=(const HealthPoints& first, const HealthPoints& other)
{
    return !(first == other);
}

 bool operator<(const HealthPoints& first, const HealthPoints& other)
{
    return (first.get_m_tempHealthPoints() < other.get_m_tempHealthPoints());

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
    return os << first.get_m_tempHealthPoints() << "(" << first.get_m_maxHealthPoints() << ")" ;
}



