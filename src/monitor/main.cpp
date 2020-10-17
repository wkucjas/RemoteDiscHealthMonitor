
#include <QApplication>
#include <QLabel>

#include "AgentsEnumerator.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    AgentsEnumerator agentsEnumerator;
    agentsEnumerator.startListening();

    QLabel l("monitor");
    l.show();

    return app.exec();
}
