
#include <QGuiApplication>
#include <QQuickItem>
#include <QQuickView>

#include "ActiveAgentsList.hpp"
#include "AgentsExplorer.hpp"


int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    ActiveAgentsList activeAgents;

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

    return app.exec();
}
