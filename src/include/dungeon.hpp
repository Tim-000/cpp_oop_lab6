#pragma once

#include <memory>
#include <string>
#include <vector>
#include "npc.hpp"
#include "observer.hpp"
#include "battle_visitor.hpp"

class Dungeon
{
private:
    std::vector<std::shared_ptr<NPC>> npcs;
    BattleVisitor battleVisitor;
    std::vector<IObserver *> observers;

public:
    explicit Dungeon(double battleRange = 100.0);

    void addNPC(const std::string &type, const std::string &name, int x, int y);
    void addObserver(IObserver *observer);

    void battle();
    void printAll() const;

    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
};
