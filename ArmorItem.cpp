#include "ArmorItem.h"
#include "Player.h"
#include <utility>

ArmorItem::ArmorItem(std::string name, int defense)
	: Item(std::move(name)), m_defense(defense)
{
}

int ArmorItem::Defense()
{
	return m_defense;
}

void ArmorItem::Apply(Player& player)
{
}
