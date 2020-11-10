#include "GeneralHealth.h"

GeneralHealth::GeneralHealth()
{
}

GeneralHealth::GeneralHealth(GeneralHealth& _health)
{
    m_status = _health.m_status;
}

GeneralHealth GeneralHealth::operator=(GeneralHealth& _health)
{
    m_status = _health.m_status;
    return *this;
}

GeneralHealth::Health GeneralHealth::GetStatus() const
{
    return m_status;
}

void GeneralHealth::SetStatus(GeneralHealth::Health _health)
{
    m_status = _health;
}