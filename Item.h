#pragma once
#include <string>

class Player;

class Item
{
public:
	explicit Item(std::string name);
	virtual ~Item() = default;

	const std::string& GetName() const;

	virtual void Apply(Player& player) = 0;

private:
	std::string m_name;
};

