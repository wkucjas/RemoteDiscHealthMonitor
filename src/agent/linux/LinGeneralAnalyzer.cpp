
#include <QProcess>

#include "common/GeneralHealth.h"
#include "common/OutputParsersUtils.h"
#include "LinGeneralAnalyzer.h"


namespace
{
    const QStringList ErrorPatterns = {
        "Buffer I/O error on device"
    };
}



LinGeneralAnalyzer::LinGeneralAnalyzer()
{
    refreshState();
}


GeneralHealth::Health LinGeneralAnalyzer::GetStatus(const Disk& disk)
{
    const QString diskId = QString::fromStdString(disk.deviceId());

    for(const QString& error: m_errorLines)
        if (error.contains(diskId))
            return GeneralHealth::Health::BAD;

    return GeneralHealth::Health::GOOD;
}


std::string LinGeneralAnalyzer::GetRawData(const Disk& disk)
{
    const QString diskId = QString::fromStdString(disk.deviceId());

    for(const QString& error: m_errorLines)
        if (error.contains(diskId))
            return error.toStdString();

    return {};
}


void LinGeneralAnalyzer::refreshState()
{
    QProcess dmesg;

    dmesg.start("dmesg", {}, QProcess::ReadOnly);
    dmesg.waitForFinished(5000);
    const QByteArray output = dmesg.readAll();

    const auto lines = ParsersUtils::clean(output);

    m_errorLines.clear();

    for(const QString& line: lines)
        for(const QString& errorPattern: ErrorPatterns)
            if (line.contains(errorPattern))
                m_errorLines.push_back(line);
}
