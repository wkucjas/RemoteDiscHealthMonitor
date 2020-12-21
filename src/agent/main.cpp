
#include <iostream>
#include <QCoreApplication>

#include "QtZeroConf/qzeroconf.h"
#include "SmartReader.h"
#include "common/constants.hpp"
#include "Server.h"
#include "windows/WinDiscCollector.h"

int main(int argc, char** argv)
{
    WinDiscCollector col;
    col.GetDiscsList();

    QCoreApplication app(argc, argv);

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish("RDHAgent", ZeroConfServiceName.toStdString().c_str(), "", RDHMPort);

    Server srv;
    srv.Init();

    app.exec();

    return 0;
}
