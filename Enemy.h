#pragma once
#include "Enitity.h"

class Enemy final: public Enitity
{
public:
	Enemy(std::string name, int maxHP, int baseAtk, int level);

	int GetLevel() const;

private:
	int m_level;
};

