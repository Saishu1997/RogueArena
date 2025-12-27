#pragma once
#include "Item.h"

class PotionItem final: public Item
{
public:
	PotionItem(std::string name, int healAmount);

	int HealAmount() const;
	void Apply(Player& player) override;

private:
	int m_healAmount;

};

