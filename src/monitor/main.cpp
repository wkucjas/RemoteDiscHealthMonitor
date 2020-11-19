
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>

#include "AgentsList.hpp"
#include "AgentsExplorer.hpp"
#include "AgentsStatusProvider.hpp"
#include "ManualAgentsValidator.hpp"
#include "common/GeneralHealth.h"
#include "Configuration.hpp"



namespace
{
    void storeHardcodedAgents(Configuration& config, const AgentsList& agentsList)
    {
        const QVector<AgentInformation>& allAgents = agentsList.agents();
        QVector<AgentInformation> hardcodedAgents;

        std::copy_if(allAgents.begin(), allAgents.end(), std::back_inserter(hardcodedAgents), [](const AgentInformation& info){
            return info.detectionSource() == AgentInformation::DetectionSource::Hardcoded;
        });

        config.storeAgents(hardcodedAgents);
    }

    void restoreHardcodedAgents(Configuration& config, AgentsList& agentsList)
    {
        QVector<AgentInformation> hardcodedAgents = config.readAgents();

        for(const auto& agent: hardcodedAgents)
            agentsList.addAgent(agent);
    }
}


int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    Configuration config;

    qmlRegisterType<GeneralHealth>("RDHM", 1, 0, "HealthEnum");

    AgentsStatusProvider statusProvider;
    AgentsList activeAgents(statusProvider);

    ManualAgentsValidator manualAgentsValdiator;
    QObject::connect(&manualAgentsValdiator, &ManualAgentsValidator::agentDiscovered,
                     &activeAgents, &AgentsList::addAgent);

    AgentsExplorer agentsEnumerator;
    QObject::connect(&agentsEnumerator, &AgentsExplorer::agentDiscovered, &activeAgents, &AgentsList::addAgent);
    QObject::connect(&agentsEnumerator, &AgentsExplorer::agentLost, &activeAgents, &AgentsList::removeAgent);

    agentsEnumerator.startListening();

    QQuickView mainWindow(QUrl("qrc:/ui/MainWindow.qml"));
    mainWindow.setResizeMode(QQuickView::SizeRootObjectToView);
    mainWindow.show();

    auto rootObject = mainWindow.rootObject();
    auto view = rootObject->findChild<QObject*>("activeAgents");
    view->setProperty("model", QVariant::fromValue(&activeAgents));
    QObject::connect(rootObject, SIGNAL(newAgentRequested(QString, QString, QString)),
                     &manualAgentsValdiator, SLOT(addNewAgent(const QString &, const QString &, const QString &)));

    restoreHardcodedAgents(config, activeAgents);

    const int exitCode = app.exec();

    storeHardcodedAgents(config, activeAgents);

    return exitCode;
}
