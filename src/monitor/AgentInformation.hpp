
#pragma once

#include <QString>

class AgentInformation
{
public:
    AgentInformation(const QString& name, const QString& host, quint16 port);

    const QString& name() const;
    const QString& host() const;
    quint16 port() const;

private:
    QString m_name;
    QString m_host;
    quint16 m_port;
};
