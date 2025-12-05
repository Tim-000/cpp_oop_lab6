#include "battle_visitor.hpp"

#include "bear.hpp"
#include "gtest/gtest.h"
#include "knight.hpp"
#include "orc.hpp"
#include "observer.hpp"
#include "point.hpp"

class DummyObserver : public IObserver
{
public:
    std::vector<std::string> messages;

    void onEvent(const std::string &msg) override
    {
        messages.push_back(msg);
    }
};

TEST(BattleVisitorTest, BearKillsKnight)
{
    Point pointBear(0, 0);
    Point pointKnight(10, 10);

    Bear bear("Baloo", pointBear);
    Knight knight("Arthur", pointKnight);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    bear.accept(visitor, knight);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Baloo killed Arthur");
}

TEST(BattleVisitorTest, OrcKillsBear)
{
    Point pointOrc(0, 0);
    Point pointBear(10, 10);

    Orc orc("Gorg", pointOrc);
    Bear bear("Baloo", pointBear);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    orc.accept(visitor, bear);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Gorg killed Baloo");
}

TEST(BattleVisitorTest, KnightKillsOrc)
{
    Point pointKnight(0, 0);
    Point pointOrc(10, 10);

    Knight knight("Arthur", pointKnight);
    Orc orc("Gorg", pointOrc);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    knight.accept(visitor, orc);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Arthur killed Gorg");
}

TEST(BattleVisitorTest, NoKillOutOfRange)
{
    Point pointBear(0, 0);
    Point pointKnight(100, 100);

    Bear bear("Baloo", pointBear);
    Knight knight("Arthur", pointKnight);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    bear.accept(visitor, knight);

    EXPECT_TRUE(observer.messages.empty());
}
