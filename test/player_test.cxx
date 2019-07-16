#include <climits>

#include "gtest/gtest.h"

// TODO(#23) actual player tests here

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
TEST_F(PlayerTest,DummyTest)
{
    ASSERT_TRUE(true);
}
