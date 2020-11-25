
#include <gmock/gmock.h>
#include <QSignalSpy>

#include "AgentsList.hpp"
#include "IAgentsStatusProviderMock.hpp"


using testing::_;
using testing::Contains;
using testing::InvokeArgument;
using testing::IsSupersetOf;
using testing::NiceMock;
using testing::UnorderedElementsAre;


TEST(AgentsListTest, isConstructible)
{
    EXPECT_TRUE( (std::is_constructible_v<AgentsList, IAgentsStatusProvider&, QObject *>) );
}


TEST(AgentsListTest, savesNewAgentInfo)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(aal.rowCount({}), 2);
}


TEST(AgentsListTest, noDuplicatesAllowed)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(aal.rowCount({}), 1);
}


TEST(AgentsListTest, doubleAgentRemoveShouldBeSafe)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    EXPECT_NO_THROW({
        aal.removeAgent(info1);
        aal.removeAgent(info1);
        aal.removeAgent(info2);
        aal.removeAgent(info2);
    });
}


TEST(AgentsListTest, agentRemoval)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    aal.removeAgent(info1);
    ASSERT_EQ(aal.rowCount({}), 1);

    const auto& agents = aal.agents();
    EXPECT_THAT(agents, Contains(info2));
}


TEST(AgentsListTest, listofAvailableRoles)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    QStringList listOfRoles;

    const auto roles = aal.roleNames();
    for(auto it = roles.begin(); it != roles.end(); ++it)
        listOfRoles.append(it.value());

    EXPECT_THAT(listOfRoles, IsSupersetOf( {"agentName", "agentHealth"} ));
}


TEST(AgentsListTest, exposesAgentsToView)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    const auto idx1 = aal.index(0, 0);
    const auto idx2 = aal.index(1, 0);

    QStringList names;
    names.append(idx1.data(AgentsList::AgentNameRole).toString());
    names.append(idx2.data(AgentsList::AgentNameRole).toString());

    EXPECT_THAT(names, UnorderedElementsAre("Krzysiu", "Zbysiu"));
}


TEST(AgentsListTest, emitsSignalsWhenAgentsAdded)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    QSignalSpy newRowsSpy(&aal, &AgentsList::rowsInserted);

    aal.addAgent(info1);
    aal.addAgent(info2);

    ASSERT_EQ(newRowsSpy.count(), 2);

    // verify first emission
    EXPECT_EQ(newRowsSpy.at(0).at(0), QModelIndex());   // no parent
    EXPECT_EQ(newRowsSpy.at(0).at(1), 0);               // first row
    EXPECT_EQ(newRowsSpy.at(0).at(2), 0);               // 1 item

    // verify second emission
    EXPECT_EQ(newRowsSpy.at(1).at(0), QModelIndex());   // no parent
    EXPECT_EQ(newRowsSpy.at(1).at(1), 1);               // second row
    EXPECT_EQ(newRowsSpy.at(1).at(2), 1);               // 1 item
}


TEST(AgentsListTest, emitsSignalsWhenAgentsRemoved)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    QSignalSpy removedRowsSpy(&aal, &AgentsList::rowsRemoved);

    aal.addAgent(info1);
    aal.addAgent(info2);

    aal.removeAgent(info2);
    aal.removeAgent(info1);

    ASSERT_EQ(removedRowsSpy.count(), 2);

    // verify first emission
    EXPECT_EQ(removedRowsSpy.at(0).at(0), QModelIndex());   // no parent
    EXPECT_EQ(removedRowsSpy.at(0).at(1), 1);               // second row
    EXPECT_EQ(removedRowsSpy.at(0).at(2), 1);               // 1 item

    // verify second emission
    EXPECT_EQ(removedRowsSpy.at(1).at(0), QModelIndex());   // no parent
    EXPECT_EQ(removedRowsSpy.at(1).at(1), 0);               // first row
    EXPECT_EQ(removedRowsSpy.at(1).at(2), 0);               // 1 item
}


TEST(AgentsListTest, itemsShouldBeChildless)
{
    NiceMock<IAgentsStatusProviderMock> statusProvider;
    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);

    aal.addAgent(info1);
    aal.addAgent(info2);

    const QModelIndex idx1 = aal.index(0, 0, {});
    const QModelIndex idx2 = aal.index(1, 0, {});

    EXPECT_EQ(aal.rowCount(idx1), 0);
    EXPECT_EQ(aal.rowCount(idx2), 0);
}


TEST(AgentsListTest, fetchHealthOfNewAgents)
{
    IAgentsStatusProviderMock statusProvider;

    AgentsList aal(statusProvider);

    AgentInformation info1("Krzysiu", "192.168.1.12", 2300, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("Zbysiu", "192.168.1.45", 2301, AgentInformation::DetectionSource::Hardcoded);


    EXPECT_CALL(statusProvider, fetchStatusOf(info1, _)).Times(1);
    EXPECT_CALL(statusProvider, fetchStatusOf(info2, _)).Times(1);

    aal.addAgent(info1);
    aal.addAgent(info2);
    aal.addAgent(info2);

    ASSERT_EQ(aal.rowCount({}), 2);
}


TEST(AgentsListTest, healthUpdatesAfterFetch)
{
    IAgentsStatusProviderMock statusProvider;

    AgentsList aal(statusProvider);

    AgentInformation info1("John Connor", "192.168.1.15", 1998, AgentInformation::DetectionSource::Hardcoded);
    AgentInformation info2("T-1000", "192.168.1.16", 1998, AgentInformation::DetectionSource::Hardcoded);

    EXPECT_CALL(statusProvider, fetchStatusOf(info1, _)).WillOnce(InvokeArgument<1>(info1, GeneralHealth::GOOD));
    EXPECT_CALL(statusProvider, fetchStatusOf(info2, _)).WillOnce(InvokeArgument<1>(info2, GeneralHealth::BAD));

    aal.addAgent(info1);
    aal.addAgent(info2);

    const QModelIndex idx1 = aal.index(0, 0);
    const QModelIndex idx2 = aal.index(1, 0);

    EXPECT_EQ(idx1.data(AgentsList::AgentHealthRole), GeneralHealth::GOOD);
    EXPECT_EQ(idx2.data(AgentsList::AgentHealthRole), GeneralHealth::BAD);
}
