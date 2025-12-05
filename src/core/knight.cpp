#include "knight.hpp"
#include "visitor.hpp"

Knight::Knight(const std::string &name, const Point &pos) : NPC(name, pos) {}

std::string Knight::getType() const
{
    return "Knight";
}

bool Knight::kills(const NPC &other) const
{
    return other.getType() == "Orc";
}

void Knight::accept(Visitor &visitor, NPC &other)
{
    visitor.visit(*this, other);
}
