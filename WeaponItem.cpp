#include "WeaponItem.h"
#include "Player.h"
#include <utility>

WeaponItem::WeaponItem(std::string name, int bonusDamage)
	: Item(std::move(name)), m_bonusDamage(bonusDamage)
{
}

int WeaponItem::BonusDamage() const
{
	return m_bonusDamage;
}

void WeaponItem::Apply(Player& player)
{
}
