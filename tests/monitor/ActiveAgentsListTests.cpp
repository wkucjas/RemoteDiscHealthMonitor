
#include <gmock/gmock.h>

#include "ActiveAgentsList.hpp"


using testing::Contains;


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


TEST(ActiveAgentsListTest, agentRemoval)
{
    ActiveAgentsList aal;

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301);

    aal.addAgent(info1);
    aal.addAgent(info2);

    aal.removeAgent(info1);
    ASSERT_EQ(aal.rowCount({}), 1);

    const auto& agents = aal.agents();
    EXPECT_THAT(agents, Contains(info2));
}
