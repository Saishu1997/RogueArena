#include "Arena.h"

#include "Enemy.h"
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "PotionItem.h"

#include <iostream>
#include <utility>

Arena::Arena() : m_rng(std::random_device{}())
{
}

void Arena::Run()
{
    Player player("Rogue");

    std::cout << "=== CONSOLE ROGUE ARENA ===\n";
    std::cout << "Survive as many rounds as you can.\n";

    int round = 1;
    while (player.isAlive())
    {
        std::cout << "\n===== ROUND " << round << " =====\n";

        auto enemy = SpawnEnemy(round);
        FightRound(player, *enemy);

        if (!player.isAlive())
            break;

        auto loot = DropLoot(round);
        LootPhase(player, std::move(loot));

        ++round;
    }

    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "Rounds survived: " << (round - 1) << "\n";
}

std::unique_ptr<Enemy> Arena::SpawnEnemy(int round)
{
    int level = round;
    int hp = 60 + round * 10;
    int atk = 10 + round * 2;

    if (round % 3 == 0)
        return std::make_unique<Enemy>("Skeleton", hp + 10, atk + 1, level);
    if (round % 2 == 0)
        return std::make_unique<Enemy>("Goblin", hp, atk, level);

    return std::make_unique<Enemy>("Bandit", hp - 5, atk + 2, level);
}

std::unique_ptr<Item> Arena::DropLoot(int round)
{
    std::uniform_int_distribution<int> dist(0, 2);
    int roll = dist(m_rng);

    if (roll == 0)
        return std::make_unique<PotionItem>("Small Potion", 25 + round * 2);
    if (roll == 1)
        return std::make_unique<WeaponItem>("Iron Blade", 3 + (round / 2));
    return std::make_unique<ArmorItem>("Leather Vest", 2 + (round / 3));
}

void Arena::FightRound(Player& player, Enemy& enemy)
{
    std::cout << "\n=== FIGHT! ===\n";
    std::cout << "An enemy appears: " << enemy.GetName() << " (Lv " << enemy.GetLevel() << ")\n";

    bool playerTurn = true;

    while (player.isAlive() && enemy.isAlive())
    {
        player.PrintStatus();
        std::cout << "Enemy: " << enemy.GetName()
            << " | HP: " << enemy.GetHP() << "/" << enemy.GetMaxHP()
            << " | ATK: " << enemy.GetAttackPower()
            << " | DEF: " << enemy.GetDefense() << "\n\n";

        if (playerTurn)
        {
            std::cout << "Choose action: [1] Attack  [2] Use Potion\n> ";
            int choice = 1;
            std::cin >> choice;

            if (choice == 2)
            {
                player.UseFirstPotion();
            }
            else
            {
                int dmg = ComputeDamage(player, enemy);
                std::cout << player.GetName() << " attacks for " << dmg << "!\n";
                enemy.TakeDamage(dmg);
            }
        }
        else
        {
            int dmg = ComputeDamage(enemy, player);
            std::cout << enemy.GetName() << " attacks for " << dmg << "!\n";
            player.TakeDamage(dmg);
        }

        playerTurn = !playerTurn;
    }

    if (!player.isAlive())
        std::cout << "\nYou were defeated...\n";
    else
        std::cout << "\nEnemy defeated!\n";
}

void Arena::LootPhase(Player& player, std::unique_ptr<Item> loot)
{
    std::cout << "\n=== LOOT DROP ===\n";
    std::cout << "You found: " << loot->GetName() << "\n";

    std::cout << "Pick up loot? [1] Yes  [2] No\n> ";
    int c = 1;
    std::cin >> c;

    if (c == 1)
    {
        player.AddToInventory(std::move(loot)); 
        std::cout << "Added to inventory.\n";
    }
    else
    {
        std::cout << "Left it behind.\n";
        return;
    }

    player.PrintInventory();
    std::cout << "\nEquip something now?\n";
    std::cout << "[1] Equip weapon  [2] Equip armor  [3] Skip\n> ";
    int e = 3;
    std::cin >> e;

    if (e == 1 || e == 2)
    {
        std::cout << "Enter inventory index to equip:\n> ";
        size_t idx = 0;
        std::cin >> idx;

        if (e == 1) player.EquipWeaponFromInventory(idx);
        else player.EquipArmorFromInventory(idx);
    }
}

int Arena::ComputeDamage(const Enitity& attacker, const Enitity& defender) const
{
	int dmg = attacker.GetAttackPower() - defender.GetDefense();
	if (dmg < 1) dmg = 1;
	return dmg;
}
