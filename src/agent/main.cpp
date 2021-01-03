
#include <iostream>
#include <QCoreApplication>

#include "QtZeroConf/qzeroconf.h"
#include "common/constants.hpp"
#include "SmartReader.h"
#include "Server.h"
#include "windows/WinGeneralAnalyzer.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish("RDHAgent", ZeroConfServiceName.toStdString().c_str(), "", RDHMPort);

    Server srv;
    srv.Init();

    app.exec();

    return 0;
}
