#include "orc.hpp"
#include "visitor.hpp"

Orc::Orc(const std::string &name, const Point &pos) : NPC(name, pos) {}

std::string Orc::getType() const
{
    return "Orc";
}

bool Orc::kills(const NPC &other) const
{
    return other.getType() == "Bear";
}

void Orc::accept(Visitor &visitor, NPC &other)
{
    visitor.visit(*this, other);
}
