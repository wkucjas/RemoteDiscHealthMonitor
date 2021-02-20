
#pragma once

#include "rep_AgentStatus_source.h"

class AgentStatus: public AgentStatusSource
{
    Q_OBJECT

public:
    AgentStatus(QObject* parent = nullptr);

    void setCounter(int counter) override;
    int counter() const override;

private:
    int m_counter;
};
