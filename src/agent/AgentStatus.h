
#pragma once

#include "rep_AgentStatus_source.h"

class AgentStatus: public AgentStatusSource
{
    Q_OBJECT

public:
    AgentStatus(QObject* parent = nullptr);

    void setOverallStatus(GeneralHealth::Health overallStatus) override;
    GeneralHealth::Health overallStatus() const override;

private:
    GeneralHealth::Health m_overallStatus;
};
