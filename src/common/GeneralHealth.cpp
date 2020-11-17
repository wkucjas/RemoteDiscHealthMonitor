#include "GeneralHealth.h"

GeneralHealth::GeneralHealth()
    : QObject()
    , m_health(UNKNOWN)
{

}


GeneralHealth::GeneralHealth(const GeneralHealth::Health& _health)
    : QObject()
    , m_health(_health)
{
}



GeneralHealth::GeneralHealth(const GeneralHealth& _health)
    : QObject()
    , m_health(_health.m_health)
{

}


GeneralHealth& GeneralHealth::operator=(const GeneralHealth& _health)
{
    m_health = _health.m_health;

    return *this;
}


GeneralHealth::Health GeneralHealth::GetStatus() const
{
    return m_health;
}


void GeneralHealth::SetStatus(GeneralHealth::Health _health)
{
    m_health = _health;
}
