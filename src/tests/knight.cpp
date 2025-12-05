#include "knight.hpp"

#include "gtest/gtest.h"
#include "bear.hpp"
#include "orc.hpp"
#include "visitor.hpp"

class DummyVisitor : public Visitor
{
public:
    bool visitedBear = false;
    bool visitedKnight = false;
    bool visitedOrc = false;

    void visit(Bear &attacker, NPC &defender) override {}
    void visit(Knight &attacker, NPC &defender) override
    {
        visitedKnight = true;
    }
    void visit(Orc &attacker, NPC &defender) override {}
};

TEST(KnightTest, ConstructorAndGetType)
{
    Point point(7, 14);
    Knight knight("Arthur", point);
    EXPECT_EQ(knight.getName(), "Arthur");
    EXPECT_EQ(knight.getType(), "Knight");
    EXPECT_EQ(knight.getPosition().getX(), 7);
    EXPECT_EQ(knight.getPosition().getY(), 14);
}

TEST(KnightTest, KillsLogic)
{
    Point point1(0, 0);
    Knight knight1("Arthur", point1);

    Point point2(1, 1);
    Orc orc1("Gorg", point2);
    Bear bear1("Baloo", point2);

    EXPECT_TRUE(knight1.kills(orc1));
    EXPECT_FALSE(knight1.kills(bear1));
    EXPECT_FALSE(knight1.kills(knight1));
}

TEST(KnightTest, AcceptVisitor)
{
    Point point1(0, 0);
    Knight knight1("Arthur", point1);

    Point point2(1, 1);
    Orc orc1("Gorg", point2);

    DummyVisitor visitor1;
    knight1.accept(visitor1, orc1);

    EXPECT_FALSE(visitor1.visitedBear);
    EXPECT_TRUE(visitor1.visitedKnight);
    EXPECT_FALSE(visitor1.visitedOrc);
}
