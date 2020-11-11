
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>

#include "ActiveAgentsList.hpp"
#include "AgentsExplorer.hpp"
#include "AgentsStatusProvider.hpp"
#include "ManualAgentsValidator.hpp"
#include "common/GeneralHealth.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

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

    return app.exec();
}
