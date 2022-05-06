#include "Mtmchkin.h"
#define DEFAULT_FORCE 5
#define DEFAULT_MAXHP 100
#define INDEX_OF_FIRST_CARD 0

Mtmchkin:: Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
m_gameStatus(GameStatus::MidGame), m_currentCard(INDEX_OF_FIRST_CARD), m_amountOfCards(numOfCards),
{
    this->m_cardARR= new Card[numOfCards];
    for (int i=0; i<numOfCards; ++i)
    {
        this->m_cardARR[i]=cardsArray[i];
    }
    this->m_player= new Player(playerName,DEFAULT_MAXHP,DEFAULT_FORCE);
}

GameStatus Mtmchkin:: getGameStatus() const
{
    return this->m_gameStatus;
}

void Mtmchkin:: playNextCard()
{

}


bool Mtmchkin:: isOver()
{

}


