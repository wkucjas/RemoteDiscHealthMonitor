
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>

#include "ActiveAgentsList.hpp"
#include "AgentsExplorer.hpp"
#include "AgentsStatusProvider.hpp"
#include "ManualAgentsValidator.hpp"
#include "common/GeneralHealth.h"
#include "Configuration.hpp"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    Configuration config;

    qmlRegisterType<GeneralHealth>("RDHM", 1, 0, "HealthEnum");

    AgentsStatusProvider statusProvider;
    ActiveAgentsList activeAgents(statusProvider);

    ManualAgentsValidator manualAgentsValdiator;
    QObject::connect(&manualAgentsValdiator, &ManualAgentsValidator::agentDiscovered,
                     &activeAgents, &ActiveAgentsList::addAgent);

    AgentsExplorer agentsEnumerator;
    QObject::connect(&agentsEnumerator, &AgentsExplorer::agentDiscovered, &activeAgents, &ActiveAgentsList::addAgent);
    QObject::connect(&agentsEnumerator, &AgentsExplorer::agentLost, &activeAgents, &ActiveAgentsList::removeAgent);

    agentsEnumerator.startListening();

    QQuickView mainWindow(QUrl("qrc:/ui/MainWindow.qml"));
    mainWindow.setResizeMode(QQuickView::SizeRootObjectToView);
    mainWindow.show();

    auto rootObject = mainWindow.rootObject();
    auto view = rootObject->findChild<QObject*>("activeAgents");
    view->setProperty("model", QVariant::fromValue(&activeAgents));
    QObject::connect(rootObject, SIGNAL(newAgentRequested(QString, QString, QString)),
                     &manualAgentsValdiator, SLOT(addNewAgent(const QString &, const QString &, const QString &)));

    const int exitCode = app.exec();

    const QVector<AgentInformation>& allAgents = activeAgents.agents();
    QVector<AgentInformation> manualAgents;
    std::copy_if(allAgents.begin(), allAgents.end(), std::back_inserter(manualAgents), [](const AgentInformation& info){
        return info.detectionSource() == AgentInformation::DetectionSource::Hardcoded;
    });

    config.storeAgents(manualAgents);

    return exitCode;
}
