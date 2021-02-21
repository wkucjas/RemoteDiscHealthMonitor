
#include "AgentStatus.h"

using namespace std::chrono_literals;


AgentStatus::AgentStatus(QObject* parent)
    : AgentStatusSource(parent)
    , m_overallStatus(GeneralHealth::UNKNOWN)
{

}

void AgentStatus::setOverallStatus(GeneralHealth::Health overallStatus)
{
    m_overallStatus = overallStatus;

    emit overallStatusChanged(m_overallStatus);
}


GeneralHealth::Health AgentStatus::overallStatus() const
{
    return m_overallStatus;
}
