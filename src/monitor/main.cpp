
#include <QGuiApplication>
#include <QQuickView>

#include "AgentsExplorer.hpp"


int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    AgentsExplorer agentsEnumerator;
    agentsEnumerator.startListening();

    QQuickView mainWindow(QUrl("qrc:/ui/MainWindow.qml"));
    mainWindow.setResizeMode(QQuickView::SizeRootObjectToView);
    mainWindow.show();

    return app.exec();
}
