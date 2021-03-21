
#include <iostream>
#include <QCoreApplication>
#include <QCommandLineParser>

#include "QtZeroConf/qzeroconf.h"
#include "common/constants.hpp"
#include "SmartReader.h"
#include "Server.h"
#include "SystemUtilitiesFactory.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("RemoteDiskHealthAgent");
    QCoreApplication::setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption nameOption(QStringList() << "n" << "name",
            QCoreApplication::translate("main", "Agent name. Visible when agent is dicovered via ZeroConf."),
            QCoreApplication::translate("main", "name"));
    parser.addOption(nameOption);

    parser.process(app);

    SystemUtilitiesFactory systemUtilsFactory;
    auto diskCollector = systemUtilsFactory.diskCollector();

    const auto disks = diskCollector->GetDisksList();

    std::cout << "Found disks:\n";

    for(const auto& disk: disks)
        std::cout << disk.GetDeviceId() << '\n';

    Server srv;
    srv.Init();

    const QString name = parser.isSet(nameOption)?
        parser.value(nameOption):
        QString("Agent %1:%2").arg(srv.ip()).arg(srv.port());

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish(name.toStdString().c_str(), ZeroConfServiceName.toStdString().c_str(), "local", RDHMPort);

    app.exec();

    return 0;
}
