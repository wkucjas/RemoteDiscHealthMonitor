#include "DiskInfo.h"



DiskInfo::DiskInfo()
{
}

DiskInfo::DiskInfo(std::string _name, GeneralHealth::Health& _health, const std::vector<ProbeStatus>& _statuses)
    : m_name(_name), m_health(_health), m_statuses(_statuses)
{
}

void DiskInfo::SetName(const std::string& _name)
{
    m_name = _name;
}

void DiskInfo::SetProbesStatuses(const std::vector<ProbeStatus>& statuses)
{
    m_statuses = statuses;
}


std::string DiskInfo::GetName() const
{
    return m_name;
};

void DiskInfo:: SetHealth(const GeneralHealth::Health& _health)
{
    m_health = _health;
}

GeneralHealth::Health DiskInfo:: GetHealth() const
{
    return m_health;
}

const std::vector<ProbeStatus> & DiskInfo::GetProbesStatuses() const
{
    return m_statuses;
}
