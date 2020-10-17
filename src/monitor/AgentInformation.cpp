
#include "AgentInformation.hpp"


AgentInformation::AgentInformation(const QString& name, const QString& host, quint16 port)
    : m_name(name)
    , m_host(host)
    , m_port(port)
{

}


const QString & AgentInformation::name() const
{
    return m_name;
}


const QString & AgentInformation::host() const
{
    return m_host;
}


quint16 AgentInformation::port() const
{
    return m_port;
}
