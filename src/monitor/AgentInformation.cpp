
#include "AgentInformation.hpp"


AgentInformation::AgentInformation(const QString& name, const QString& host, quint16 port)
    : m_name(name)
    , m_host(host)
    , m_port(port)
{

}


const QString& AgentInformation::name() const
{
    return m_name;
}


const QString& AgentInformation::host() const
{
    return m_host;
}


quint16 AgentInformation::port() const
{
    return m_port;
}


bool AgentInformation::operator==(const AgentInformation& other) const
{
    return std::tie(m_port, m_host, m_name) == std::tie(other.m_port, other.m_host, other.m_name);
}
