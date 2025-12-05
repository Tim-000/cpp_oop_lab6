#pragma once

#include <string>
#include <vector>
#include "visitor.hpp"

class NPC;
class Bear;
class Knight;
class Orc;
class IObserver;

struct BattleResult
{
    NPC *dead1 = nullptr;
    NPC *dead2 = nullptr;
};

class BattleVisitor : public Visitor
{
private:
    double attackRange;
    std::vector<IObserver *> observers;
    std::vector<BattleResult> results;

    void notify(const std::string &msg);
    BattleResult resolve(NPC &attacker, NPC &defender);
    void addResult(const BattleResult &r) { results.push_back(r); }

public:
    explicit BattleVisitor(double range);
    void addObserver(IObserver *obs);

    void visit(Bear &attacker, NPC &defender) override;
    void visit(Knight &attacker, NPC &defender) override;
    void visit(Orc &attacker, NPC &defender) override;

    bool hasResults() const { return !results.empty(); }
    BattleResult popResult()
    {
        BattleResult r = results.back();
        results.pop_back();
        return r;
    }
};
