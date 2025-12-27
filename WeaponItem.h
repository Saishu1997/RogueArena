#pragma once
#include "Item.h"

class WeaponItem final: public Item
{
public:
	WeaponItem(std::string name, int bonusDamage);

	int BonusDamage() const;
	void Apply(Player& player) override;

private:
	int m_bonusDamage;
};

