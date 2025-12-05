#include "npc.factory.hpp"

#include "bear.hpp"
#include "gtest/gtest.h"
#include "knight.hpp"
#include "orc.hpp"

TEST(NPCFactoryTest, CreateBear)
{
    std::shared_ptr<NPC> bear = NPCFactory::create("Bear", "Baloo", 10, 20);
    ASSERT_NE(bear, nullptr);
    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getName(), "Baloo");
    EXPECT_EQ(bear->getPosition().getX(), 10);
    EXPECT_EQ(bear->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, CreateOrc)
{
    std::shared_ptr<NPC> orc = NPCFactory::create("Orc", "Gorg", 5, 15);
    ASSERT_NE(orc, nullptr);
    EXPECT_EQ(orc->getType(), "Orc");
    EXPECT_EQ(orc->getName(), "Gorg");
    EXPECT_EQ(orc->getPosition().getX(), 5);
    EXPECT_EQ(orc->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, CreateKnight)
{
    std::shared_ptr<NPC> knight = NPCFactory::create("Knight", "Arthur", 7, 14);
    ASSERT_NE(knight, nullptr);
    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(knight->getName(), "Arthur");
    EXPECT_EQ(knight->getPosition().getX(), 7);
    EXPECT_EQ(knight->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, CreateUnknownType)
{
    std::shared_ptr<NPC> unknown1 = NPCFactory::create("Dragon", "Drako", 0, 0);
    EXPECT_EQ(unknown1, nullptr);
}

TEST(NPCFactoryTest, FromStringCreatesBear)
{
    std::shared_ptr<NPC> bearFromString = NPCFactory::fromString("Bear Baloo 10 20");
    ASSERT_NE(bearFromString, nullptr);
    EXPECT_EQ(bearFromString->getType(), "Bear");
    EXPECT_EQ(bearFromString->getName(), "Baloo");
    EXPECT_EQ(bearFromString->getPosition().getX(), 10);
    EXPECT_EQ(bearFromString->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, FromStringCreatesOrc)
{
    std::shared_ptr<NPC> orcFromString = NPCFactory::fromString("Orc Gorg 5 15");
    ASSERT_NE(orcFromString, nullptr);
    EXPECT_EQ(orcFromString->getType(), "Orc");
    EXPECT_EQ(orcFromString->getName(), "Gorg");
    EXPECT_EQ(orcFromString->getPosition().getX(), 5);
    EXPECT_EQ(orcFromString->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, FromStringCreatesKnight)
{
    std::shared_ptr<NPC> knightFromString = NPCFactory::fromString("Knight Arthur 7 14");
    ASSERT_NE(knightFromString, nullptr);
    EXPECT_EQ(knightFromString->getType(), "Knight");
    EXPECT_EQ(knightFromString->getName(), "Arthur");
    EXPECT_EQ(knightFromString->getPosition().getX(), 7);
    EXPECT_EQ(knightFromString->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, FromStringUnknownType)
{
    std::shared_ptr<NPC> unknownFromString = NPCFactory::fromString("Dragon Drako 0 0");
    EXPECT_EQ(unknownFromString, nullptr);
}
