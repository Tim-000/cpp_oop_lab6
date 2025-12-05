#include "npc.factory.hpp"

#include "bear.hpp"
#include "knight.hpp"
#include "orc.hpp"

std::shared_ptr<NPC> NPCFactory::create(const std::string &type, const std::string &name, int x,
                                        int y)
{
    if (type == "Bear")
        return std::make_shared<Bear>(name, Point(x, y));
    if (type == "Knight")
        return std::make_shared<Knight>(name, Point(x, y));
    if (type == "Orc")
        return std::make_shared<Orc>(name, Point(x, y));
    return nullptr;
}

std::shared_ptr<NPC> NPCFactory::fromString(const std::string &line)
{
    std::stringstream ss(line);
    std::string type, name;
    int x, y;
    ss >> type >> name >> x >> y;
    return create(type, name, x, y);
}
