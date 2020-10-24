
#include <gmock/gmock.h>
#include <QSignalSpy>

#include "ActiveAgentsList.hpp"


using testing::Contains;
using testing::IsSupersetOf;
using testing::UnorderedElementsAre;

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


TEST(ActiveAgentsListTest, listofAvailableRoles)
{
    ActiveAgentsList aal;

    QStringList listOfRoles;

    const auto roles = aal.roleNames();
    for(auto it = roles.begin(); it != roles.end(); ++it)
        listOfRoles.append(it.value());

    EXPECT_THAT(listOfRoles, IsSupersetOf( {"agentName"} ));
}


TEST(ActiveAgentsListTest, exposesAgentsToView)
{
    ActiveAgentsList aal;

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301);

    aal.addAgent(info1);
    aal.addAgent(info2);

    const auto idx1 = aal.index(0, 0);
    const auto idx2 = aal.index(1, 0);

    QStringList names;
    names.append(idx1.data(ActiveAgentsList::AgentNameRole).toString());
    names.append(idx2.data(ActiveAgentsList::AgentNameRole).toString());

    EXPECT_THAT(names, UnorderedElementsAre("Krzysiu", "Zbysiu"));
}


TEST(ActiveAgentsListTest, emitsSignalsWhenAgentsAdded)
{
    ActiveAgentsList aal;

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301);

    QSignalSpy newRowsSpy(&aal, &ActiveAgentsList::rowsInserted);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(newRowsSpy.count(), 2);

    // verify first emission
    EXPECT_EQ(newRowsSpy.at(0).at(0), QModelIndex());   // no parent
    EXPECT_EQ(newRowsSpy.at(0).at(1), 0);               // first row
    EXPECT_EQ(newRowsSpy.at(0).at(2), 0);               // 1 item

    // verify second emission
    EXPECT_EQ(newRowsSpy.at(1).at(0), QModelIndex());   // no parent
    EXPECT_EQ(newRowsSpy.at(1).at(1), 1);               // first row
    EXPECT_EQ(newRowsSpy.at(1).at(2), 1);               // 1 item
}
