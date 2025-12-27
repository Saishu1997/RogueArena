#include "PotionItem.h"
#include "Player.h"
#include <utility>

PotionItem::PotionItem(std::string name, int healAmount)
	: Item(std::move(name)), m_healAmount(healAmount)
{
}

int PotionItem::HealAmount() const
{
	return m_healAmount;
}

void PotionItem::Apply(Player& player)
{
	player.Heal(m_healAmount);
}
