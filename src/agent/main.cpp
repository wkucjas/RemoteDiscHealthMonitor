
#include <iostream>
#include <QCoreApplication>

#include "QtZeroConf/qzeroconf.h"
#include "HealthChecker.h"
#include "SmartReader.h"
#include "common/constants.hpp"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QZeroConf zeroConf;
    zeroConf.addServiceTxtRecord("RDHAgent");
    zeroConf.startServicePublish("RDHAgent", ZeroConfServiceName.toStdString().c_str(), "", RDHMPort);

    SmartReader smartReader;
	HealthChecker checker(smartReader);

	std::string health = checker.CheckDiscHealth();

	std::cout << health;

    app.exec();

	return 0;
}
