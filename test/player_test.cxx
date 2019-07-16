#include <climits>
#include <string>

#include "gtest/gtest.h"

#include "player.h"

class PlayerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

// NOLINTNEXTLINE
TEST_F(PlayerTest,GetName)
{
    std::string p2_name = "Player 2";
    constexpr int p2_x = 10;
    constexpr int p2_y = 20;

    Player player2{p2_name, p2_x, p2_y};

    ASSERT_EQ(p2_name, player2.getName()); // NOLINT
}

// NOLINTNEXTLINE
TEST_F(PlayerTest,GetCoordinates)
{
    std::string p2_name = "Player 2";
    constexpr int p2_x = 10;
    constexpr int p2_y = 20;

    Player player2{p2_name, p2_x, p2_y};

    ASSERT_EQ(p2_x, player2.getPosition().getX()); // NOLINT
    ASSERT_EQ(p2_y, player2.getPosition().getY()); // NOLINT
}
