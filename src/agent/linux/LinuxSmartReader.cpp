
#include <QProcess>
#include <QDebug>

#include "../SmartReader.h"
#include "SmartCtlOutputParser.h"


std::string SmartReader::ReadSMARTData(const Disk &)
{
    QProcess smartctl;

    smartctl.start("smartctl", { "-a", "/dev/sda" }, QProcess::ReadOnly);
    smartctl.waitForFinished(5000);
    const QByteArray output = smartctl.readAll();

    qDebug() << output;

    SmartCtlOutputParser::parse(output);

    return {};
}


GeneralHealth SmartReader::ReadDisksStatus(const Disk &)
{
    return GeneralHealth::GOOD;
}
