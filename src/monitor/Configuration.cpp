
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
        result += ",";
        result += QString::number(static_cast<int>(agent.detectionSource()));

        return result;
    }

    QString agentsToString(const QVector<AgentInformation>& agents)
    {
        QStringList result;

        for(const auto& agent: agents)
            result.append(agentToString(agent));

        return result.join(";");
    }

    std::optional<AgentInformation> stringToAgent(const QString& rawAgent)
    {
        std::optional<AgentInformation> result;

        const QStringList agentSplitted = rawAgent.split(",");

        if (agentSplitted.size() == 4)
        {
            AgentInformation info(QByteArray::fromBase64(agentSplitted[0].toUtf8()),
                                  QByteArray::fromBase64(agentSplitted[1].toUtf8()),
                                  agentSplitted[2].toInt(),
                                  static_cast<AgentInformation::DetectionSource>(agentSplitted[3].toInt()));

            result = info;
        }

        return result;
    }

    QVector<AgentInformation> stringToAgents(const QString& rawAgentsList)
    {
        QStringList rawAgentsListSplitted = rawAgentsList.split(";");
        QVector<AgentInformation> result;

        for(const QString& rawAgent: rawAgentsListSplitted)
        {
            const auto info = stringToAgent(rawAgent);

            if (info)
                result.append(*info);
        }

        return result;
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


QVector<AgentInformation> Configuration::readAgents()
{
    const QString rawList = m_settings.value("agents").toString();

    return stringToAgents(rawList);
}
