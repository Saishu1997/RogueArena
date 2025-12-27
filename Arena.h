#pragma once
#include "Player.h"
#include <memory>
#include <random>

class Enemy;
class Item;

class Arena
{
public:
    Arena();

    void Run();

private:
    std::unique_ptr<Enemy> SpawnEnemy(int round);
    std::unique_ptr<Item> DropLoot(int round);

    void FightRound(Player& player, Enemy& enemy);
    void LootPhase(Player& player, std::unique_ptr<Item> loot);

    int ComputeDamage(const Enitity& attacker, const Enitity& defender) const;

private:
    std::mt19937 m_rng;
};

