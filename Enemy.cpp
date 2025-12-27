#include "Enemy.h"
#include <utility>

Enemy::Enemy(std::string name, int maxHP, int baseAtk, int level)
	: Enitity(std::move(name), maxHP, baseAtk), m_level(level)
{
}

int Enemy::GetLevel() const
{
	return m_level;
}
