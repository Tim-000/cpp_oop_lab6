#pragma once

class Orc;
class Knight;
class Bear;
class NPC;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(Orc &attacker, NPC &defender) = 0;
    virtual void visit(Knight &attacker, NPC &defender) = 0;
    virtual void visit(Bear &attacker, NPC &defender) = 0;
};
