#include "bear.hpp"

#include "gtest/gtest.h"
#include "knight.hpp"
#include "orc.hpp"
#include "visitor.hpp"

class DummyVisitor : public Visitor
{
public:
    bool visitedBear = false;
    bool visitedKnight = false;
    bool visitedOrc = false;

    void visit(Bear &attacker, NPC &defender) override
    {
        visitedBear = true;
    }
    void visit(Knight &attacker, NPC &defender) override
    {
        visitedKnight = true;
    }
    void visit(Orc &attacker, NPC &defender) override
    {
        visitedOrc = true;
    }
};

TEST(BearTest, ConstructorAndGetType)
{
    Point point(10, 20);
    Bear bear("Baloo", point);
    EXPECT_EQ(bear.getName(), "Baloo");
    EXPECT_EQ(bear.getType(), "Bear");
    EXPECT_EQ(bear.getPosition().getX(), 10);
    EXPECT_EQ(bear.getPosition().getY(), 20);
}

TEST(BearTest, KillsLogic)
{
    Point point1(0, 0);
    Bear bear1("Baloo", point1);

    Point point2(1, 1);
    Knight knight1("Arthur", point2);
    Orc orc1("Gorg", point2);

    EXPECT_TRUE(bear1.kills(knight1));
    EXPECT_FALSE(bear1.kills(orc1));
    EXPECT_FALSE(bear1.kills(bear1));
}

TEST(BearTest, AcceptVisitor)
{
    Point point1(0, 0);
    Bear bear1("Baloo", point1);

    Point point2(1, 1);
    Knight knight1("Arthur", point2);

    DummyVisitor visitor1;
    bear1.accept(visitor1, knight1);

    EXPECT_TRUE(visitor1.visitedBear);
    EXPECT_FALSE(visitor1.visitedKnight);
    EXPECT_FALSE(visitor1.visitedOrc);
}
