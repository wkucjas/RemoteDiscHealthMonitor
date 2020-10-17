
#include <QApplication>
#include <QLabel>

#include "AgentsExplorer.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    AgentsExplorer agentsEnumerator;
    agentsEnumerator.startListening();

    QLabel l("monitor");
    l.show();

    return app.exec();
}
