#pragma once
#include "Item.h"

class ArmorItem final: public Item
{
public:
	ArmorItem(std::string name, int defense);

	int Defense();
	void Apply(Player& player) override;

private:
	int m_defense;
};

