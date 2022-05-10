#include "Mtmchkin.h"
#define INDEX_OF_FIRST_CARD 0

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
        m_gameStatus(GameStatus::MidGame), m_currentCard(INDEX_OF_FIRST_CARD), m_amountOfCards(numOfCards),
        m_player(playerName)
{
    this->m_cardARR= new Card[numOfCards];
    for (int i=0; i<numOfCards; ++i)
    {
        this->m_cardARR[i]=cardsArray[i];
    }
}

Mtmchkin::Mtmchkin(const Mtmchkin& m) : m_gameStatus(m.m_gameStatus), m_currentCard(m.m_currentCard),
                                        m_amountOfCards(m.m_amountOfCards),m_player(m.m_player)
{
    this->m_cardARR= new Card[m_amountOfCards];
    for (int i=0; i<m_amountOfCards; ++i)
    {
        this->m_cardARR[i]=m.m_cardARR[i];
    }
}


Mtmchkin::~Mtmchkin()
{
    delete[] this->m_cardARR;
}


Mtmchkin& Mtmchkin:: operator=(Mtmchkin &m)
{
    if (this == &m)
    {
        return *this;
    }

    delete[] this->m_cardARR;
    this->m_gameStatus = m.m_gameStatus;
    this->m_currentCard = m.m_currentCard;
    this->m_amountOfCards = m.m_amountOfCards;
    this->m_player = m.m_player;
    this->m_cardARR = new Card[m_amountOfCards];

    for(int i=0; i < m_amountOfCards; i++)
    {
        m_cardARR[i] = m.m_cardARR[i];
    }

    return *this;
}


GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}

void Mtmchkin::playNextCard()
{
    if(this->m_gameStatus != GameStatus::MidGame)
    {
        return;
    }
    this->m_cardARR[this->m_currentCard].printInfo();
    this->m_cardARR[this->m_currentCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    if(this->m_player.getLevel() == 10)
    {
        this->m_gameStatus= GameStatus::Win;
    }
    if(this->m_player.isKnockedOut())
    {
        this->m_gameStatus= GameStatus::Loss;
    }
    if(this->m_currentCard == this->m_amountOfCards -1)
    {
        this->m_currentCard= INDEX_OF_FIRST_CARD;
    }
    else
    {
        ++this->m_currentCard;
    }
}



bool Mtmchkin::isOver() const
{
    if(this->m_gameStatus == GameStatus::Loss || this->m_gameStatus == GameStatus::Win)
    {
        return true;
    }
    return false;
}

