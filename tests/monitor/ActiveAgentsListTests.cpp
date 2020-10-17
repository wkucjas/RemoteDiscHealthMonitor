
#include <gtest/gtest.h>

#include "ActiveAgentsList.hpp"


TEST(ActiveAgentsListTest, isConstructible)
{
    EXPECT_TRUE(std::is_constructible_v<ActiveAgentsList>);
}
