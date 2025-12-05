#include "dungeon.hpp"
#include "npc.factory.hpp"
#include "observer_console.hpp"

int main()
{
    ConsoleLogger logger;

    Dungeon dungeon(100.0);
    dungeon.addObserver(&logger);

    dungeon.addNPC("Bear", "Baloo", 0, 0);
    dungeon.addNPC("Orc", "Gorg", 10, 10);
    dungeon.addNPC("Knight", "Arthur", 5, 5);

    dungeon.battle();

    dungeon.printAll();

    return 0;
}
