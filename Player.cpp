#include "Player.h"
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "PotionItem.h"

#include <iostream>
#include <utility>


Player::Player(std::string name) : Enitity(std::move(name), 120, 12)
{
}

void Player::AddToInventory(std::unique_ptr<Item> item)
{
	m_inventory.emplace_back(std::move(item));
}

bool Player::HasPotion() const
{
	for (const auto& it : m_inventory)
	{
		if (dynamic_cast<const PotionItem*>(it.get()) != nullptr)
			return true;
	}
	return false;
}

void Player::EquipWeaponFromInventory(size_t index)
{
	if (index >= m_inventory.size())
		return;

	auto* weapon = dynamic_cast<WeaponItem*>(m_inventory[index].get());
	if (!weapon)
		return;

	m_weapon.reset(static_cast<WeaponItem*>(m_inventory[index].release()));
	m_inventory.erase(m_inventory.begin() + static_cast<long long>(index));

	std::cout << "Equipped weapon: " << m_weapon->GetName() << " (+" << m_weapon->BonusDamage() << " ATK)\n";
}

void Player::EquipArmorFromInventory(size_t index)
{
	if (index >= m_inventory.size())
		return;

	auto* armor = dynamic_cast<ArmorItem*>(m_inventory[index].get());
	if (!armor)
		return;

	m_armor.reset(static_cast<ArmorItem*>(m_inventory[index].release()));
	m_inventory.erase(m_inventory.begin() + static_cast<long long>(index));

	SetDefense(m_armor->Defense());

	std::cout << "Equipped armor: " << m_armor->GetName() << " (DEF " << m_armor->Defense() << ")\n";
}

void Player::UseFirstPotion()
{
	for (size_t i = 0; i < m_inventory.size(); ++i)
	{
		auto* potion = dynamic_cast<PotionItem*>(m_inventory[i].get());
		if (!potion)
			continue;

		std::cout << "Used potion: " << potion->GetName() << " (Heal " << potion->GetName()
			<< " (Heal " << potion->HealAmount() << ")\n";

		potion->Apply(*this);

		m_inventory.erase(m_inventory.begin() + static_cast<long long>(i));
		return;
	}

	std::cout << "No Potion available. \n";
}

int Player::GetAttackPower() const
{
	int atk = m_baseAtk;
	if (m_weapon) atk += m_weapon->BonusDamage();
	return atk;
}

void Player::PrintStatus() const
{
	std::cout << "\nPlayer: " << m_name
		<< " | HP: " << m_hp << "/" << m_maxHP
		<< " | ATK: " << GetAttackPower()
		<< " | DEF: " << m_defense << "\n";

	if (m_weapon)
		std::cout << "  Weapon: " << m_weapon->GetName()
		<< " (+" << m_weapon->BonusDamage() << ")\n";
	else
		std::cout << "  Weapon: None\n";

	if (m_armor)
		std::cout << "  Armor : " << m_armor->GetName()
		<< " (DEF " << m_armor->Defense() << ")\n";
	else
		std::cout << "  Armor : None\n";
}

void Player::PrintInventory() const
{
	std::cout << "\nInventory:\n";
	if (m_inventory.empty())
	{
		std::cout << "  (empty)\n";
		return;
	}

	for (size_t i = 0; i < m_inventory.size(); ++i)
	{
		std::cout << "  [" << i << "] " << m_inventory[i]->GetName() << "\n";
	}
}
