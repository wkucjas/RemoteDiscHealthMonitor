
#include <QByteArray>

#include "common/constants.hpp"
#include "Configuration.hpp"


namespace
{
    QString agentToString(const AgentInformation& agent)
    {
        QString result;
        result += agent.name().toUtf8().toBase64();
        result += ",";
        result += agent.host().toUtf8().toBase64();
        result += ",";
        result += QString::number(agent.port());

        return result;
    }

    QString agentsToString(const QVector<AgentInformation>& agents)
    {
        QStringList result;

        for(const auto& agent: agents)
            result.append(agentToString(agent));

        return result.join(";");
    }
}


Configuration::Configuration()
    : m_settings(QSettings::IniFormat, QSettings::UserScope, ApplicationShortName, ApplicationShortName)
{

}


Configuration::~Configuration()
{

}


void Configuration::storeAgents(const QVector<AgentInformation>& agents)
{
    m_settings.setValue("agents", agentsToString(agents));
}
