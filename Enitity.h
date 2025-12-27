#pragma once
#include <string>

class Enitity
{
public:
	Enitity(std::string name, int maxHP, int baseAtk);
	virtual ~Enitity() = default;

	const std::string& GetName() const;
	int GetHP() const;
	int GetMaxHP() const;

	bool isAlive() const;

	int GetBaseAttack() const;
	int GetDefense() const;

	void SetDefense(int def);

	virtual int GetAttackPower() const;
	virtual void TakeDamage(int dmg);
	void Heal(int amount);

protected:
	std::string m_name;
	int m_hp;
	int m_maxHP;
	int m_baseAtk;
	int m_defense;
};

