
#include <QProcess>

#include "common/GeneralHealth.h"
#include "LinGeneralAnalyzer.h"
#include "DmesgParser.h"
#include "IPartitionsManager.h"


LinGeneralAnalyzer::LinGeneralAnalyzer(const IPartitionsManager& manager)
    : m_partitionsManager(manager)
{
    refreshState();
}


GeneralHealth::Health LinGeneralAnalyzer::GetStatus(const Disk& disk)
{
    return m_errors.find(disk) == m_errors.end()?
        GeneralHealth::Health::GOOD :
        GeneralHealth::Health::BAD;
}


std::string LinGeneralAnalyzer::GetRawData(const Disk& disk)
{
    std::string result;

    auto it = m_errors.find(disk);

    if (it != m_errors.end())
    {
        QStringList errors;
        std::copy(it->second.begin(), it->second.end(), std::back_inserter(errors));

        const QString errorline = errors.join('\n');
        result = errorline.toStdString();
    }

    return result;
}


void LinGeneralAnalyzer::refreshState()
{
    QProcess dmesg;

    dmesg.start("dmesg", {}, QProcess::ReadOnly);
    dmesg.waitForFinished(5000);
    const QByteArray output = dmesg.readAll();

    DmesgParser dmesgParser(m_partitionsManager);

    m_errors = dmesgParser.parse(output);
}
