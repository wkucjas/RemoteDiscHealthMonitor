
#include <iostream>
#include <QCoreApplication>

#include "QtZeroConf/qzeroconf.h"
#include "common/constants.hpp"
#include "SmartReader.h"
#include "Server.h"
#include "SystemUtilitiesFactory.h"
#include "windows/WinGeneralAnalyzer.h"
#include "DiscStatusCalculator.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    SystemUtilitiesFactory systemUtilsFactory;
    auto diskCollector = systemUtilsFactory.diskCollector();
    auto discCollection = diskCollector->GetDisksList();
    std::vector< DiscStatusCalculator::ProbePtr> probes;
    std::unique_ptr<IProbe> probe(new WinGeneralAnalyzer());
    probes.emplace_back(std::move(probe));

    DiscStatusCalculator calc(probes, discCollection);
    auto stat = calc.GetStatus();
    

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish("RDHAgent", ZeroConfServiceName.toStdString().c_str(), "", RDHMPort);

    Server srv;
    srv.Init();

    app.exec();

    return 0;
}
