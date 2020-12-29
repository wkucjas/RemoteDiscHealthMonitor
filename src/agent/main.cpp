
#include <iostream>
#include <QCoreApplication>

#include "QtZeroConf/qzeroconf.h"
#include "common/constants.hpp"
#include "SmartReader.h"
#include "Server.h"
#include "SystemUtilitiesFactory.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    SystemUtilitiesFactory systemUtilsFactory;
    auto diskCollector = systemUtilsFactory.diskCollector();

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish("RDHAgent", ZeroConfServiceName.toStdString().c_str(), "", RDHMPort);

    Server srv;
    srv.Init();

    app.exec();

    return 0;
}
