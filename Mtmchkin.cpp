#include "Mtmchkin.h"
#define DEFAULT_FORCE 5
#define DEFAULT_MAXHP 100
#define INDEX_OF_FIRST_CARD 0

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
m_gameStatus(GameStatus::MidGame), m_currentCard(INDEX_OF_FIRST_CARD), m_amountOfCards(numOfCards),
{
    this->m_cardARR= new Card[numOfCards];
    for (int i=0; i<numOfCards; ++i)
    {
        this->m_cardARR[i]=cardsArray[i];
    }
    this->m_player= new Player(playerName);
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_gameStatus;
}

void Mtmchkin::playNextCard()
{
    if(this->m_currentCard == this->m_amountOfCards -1)
    {
        this->m_currentCard= INDEX_OF_FIRST_CARD;
    }
    else
    {
        ++this->m_currentCard;
    }
    this->m_cardARR[this->m_currentCard].printInfo();
    this->m_cardARR[this->m_currentCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    if(this->m_player.getLevel == 10)
    {
        this->m_gameStatus= GameStatus::Win;
    }
    if(this->m_player.isKnockedOut())
    {
        this->m_gameStatus= GameStatus::Loss;  
    }   
}


bool Mtmchkin::isOver()
{
    if(this->m_gameStatus == GameStatus::Loss || this->m_gameStatus == GameStatus::Win)
    {
        return true;
    }
    return false;
}



