#include "GeneralHealth.h"

GeneralHealth::GeneralHealth()
    : m_health(UNKNOWN)
{

}


GeneralHealth::GeneralHealth(const GeneralHealth::Health& _health)
    : m_health(_health)
{
}


GeneralHealth::Health GeneralHealth::GetStatus() const
{
    return m_health;
}


void GeneralHealth::SetStatus(GeneralHealth::Health _health)
{
    m_health = _health;
}
