#pragma once
#include "Enitity.h"
#include <memory>
#include <vector>

class Item;
class WeaponItem;
class ArmorItem;

class Player final: public Enitity
{
public:
	Player(std::string name);

	void AddToInventory(std::unique_ptr<Item> item);
	bool HasPotion() const;

	void EquipWeaponFromInventory(size_t index);
	void EquipArmorFromInventory(size_t index);

	void UseFirstPotion();

	int GetAttackPower() const override;

	void PrintStatus() const;
	void PrintInventory() const;

private:
	std::vector<std::unique_ptr<Item>> m_inventory;

	std::unique_ptr<WeaponItem> m_weapon;
	std::unique_ptr<ArmorItem> m_armor;
};

