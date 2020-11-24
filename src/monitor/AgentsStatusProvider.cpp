
#include "AgentsStatusProvider.hpp"
#include "AgentStatusFetcher.hpp"


void AgentsStatusProvider::fetchStatusOf(const AgentInformation& info, const IAgentsStatusProvider::StatusCallback& callback)
{
    AgentStatusFetcher* statusProvider = new AgentStatusFetcher(info);

    QObject::connect(statusProvider, &AgentStatusFetcher::statusAvailable, [info, callback, statusProvider](const GeneralHealth::Health& health) {
        callback(info, health);
        statusProvider->deleteLater();
    });
}
