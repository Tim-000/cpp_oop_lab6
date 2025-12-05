#include "orc.hpp"

#include "gtest/gtest.h"
#include "bear.hpp"
#include "knight.hpp"
#include "visitor.hpp"

class DummyVisitor : public Visitor
{
public:
    bool visitedBear = false;
    bool visitedKnight = false;
    bool visitedOrc = false;

    void visit(Bear &attacker, NPC &defender) override {}
    void visit(Knight &attacker, NPC &defender) override {}
    void visit(Orc &attacker, NPC &defender) override
    {
        visitedOrc = true;
    }
};

TEST(OrcTest, ConstructorAndGetType)
{
    Point point(5, 10);
    Orc orc("Gorg", point);
    EXPECT_EQ(orc.getName(), "Gorg");
    EXPECT_EQ(orc.getType(), "Orc");
    EXPECT_EQ(orc.getPosition().getX(), 5);
    EXPECT_EQ(orc.getPosition().getY(), 10);
}

TEST(OrcTest, KillsLogic)
{
    Point point1(0, 0);
    Orc orc1("Gorg", point1);

    Point point2(1, 1);
    Bear bear1("Baloo", point2);
    Knight knight1("Arthur", point2);

    EXPECT_TRUE(orc1.kills(bear1));
    EXPECT_FALSE(orc1.kills(knight1));
    EXPECT_FALSE(orc1.kills(orc1));
}

TEST(OrcTest, AcceptVisitor)
{
    Point point1(0, 0);
    Orc orc1("Gorg", point1);

    Point point2(1, 1);
    Bear bear1("Baloo", point2);

    DummyVisitor visitor1;
    orc1.accept(visitor1, bear1);

    EXPECT_FALSE(visitor1.visitedBear);
    EXPECT_FALSE(visitor1.visitedKnight);
    EXPECT_TRUE(visitor1.visitedOrc);
}
