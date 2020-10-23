
#include <gtest/gtest.h>

#include "ActiveAgentsList.hpp"


TEST(ActiveAgentsListTest, isConstructible)
{
    EXPECT_TRUE(std::is_constructible_v<ActiveAgentsList>);
}


TEST(ActiveAgentsListTest, savesNewAgentInfo)
{
    ActiveAgentsList aal;

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(aal.rowCount({}), 2);
}


TEST(ActiveAgentsListTest, noDuplicatesAllowed)
{
    ActiveAgentsList aal;

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300);
    AgentInformation info2("Krzysiu", "192.168.1.12", 2300);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(aal.rowCount({}), 1);
}
