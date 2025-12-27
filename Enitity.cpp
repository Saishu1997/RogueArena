#include "Enitity.h"
#include <algorithm>

Enitity::Enitity(std::string name, int maxHP, int baseAtk) 
	: m_name(std::move(name)), m_hp(maxHP), m_maxHP(maxHP), m_baseAtk(baseAtk), m_defense(0)
{
}

const std::string& Enitity::GetName() const
{
	return m_name;
}

int Enitity::GetHP() const
{
	return m_hp;
}

int Enitity::GetMaxHP() const
{
	return m_maxHP;
}

bool Enitity::isAlive() const
{
	return m_hp > 0;
}

int Enitity::GetBaseAttack() const
{
	return m_baseAtk;
}

int Enitity::GetDefense() const
{
	return m_defense;
}

void Enitity::SetDefense(int def)
{
	m_defense = std::max(0, def);
}

int Enitity::GetAttackPower() const
{
	return m_baseAtk;
}

void Enitity::TakeDamage(int dmg)
{
	dmg = std::max(0, dmg);
	m_hp = std::max(0, m_hp - dmg);
}

void Enitity::Heal(int amount)
{
	amount = std::max(0, amount);
	m_hp = std::min(m_maxHP, m_hp + amount);
}
