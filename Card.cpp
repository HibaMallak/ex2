#include "Card.h"
#define WIN true
#define LOSS false

Card::Card(CardType type, const CardStats &stats) : m_effect(type), m_stats(stats)
{
    if (type == CardType::Battle)
    {
        this->m_stats.loot=stats.loot;
        this->m_stats.force=stats.force;
        this->m_stats.hpLossOnDefeat=stats.hpLossOnDefeat;
    }

    if (type == CardType::Buff)
    {
        this->m_stats.cost=stats.cost;
        this->m_stats.buff=stats.buff;
    }

    if (type == CardType::Treasure)
    {
        this->m_stats.loot=stats.loot;
    }

    if (type == CardType::Heal)
    {
        this->m_stats.cost=stats.cost;
        this->m_stats.heal=stats.heal;
    }
}


void Card::applyEncounter(Player& player) const
{

    if (this->m_effect== CardType::Battle)
    {
        if (player.getAttackStrength() >= this->m_stats.force)
        {
            player.levelUp();
            player.addCoins(this->m_stats.loot) ;
            printBattleResult(WIN);
        }
        else
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(LOSS);
        }
    }

    if (this->m_effect== CardType::Heal && player.pay(this->m_stats.cost))
    {
            player.heal(this->m_stats.heal);
    }

    if (this->m_effect== CardType::Buff && player.pay(this->m_stats.cost))
    {
        player.buff(this->m_stats.buff);
    }

    if (this->m_effect== CardType::Treasure)
    {
        player.addCoins(this->m_stats.loot);
    }
}

void Card:: printInfo() const
{

    if (this->m_effect== CardType::Treasure)
    {
        printTreasureCardInfo(this->m_stats);
    }

    if (this->m_effect== CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
    }

    if (this->m_effect== CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }

    if (this->m_effect== CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
    }

}
