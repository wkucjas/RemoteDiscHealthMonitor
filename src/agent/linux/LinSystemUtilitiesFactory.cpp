
#include <QProcess>

#include "../SystemUtilitiesFactory.h"
#include "LinuxDiskCollector.h"
#include "LinGeneralAnalyzer.h"
#include "LsblkOutputParser.h"


struct SystemUtilitiesFactory::State
{
    State()
    {
        QProcess lsblk;

        lsblk.start("lsblk", { "-rMb" }, QProcess::ReadOnly);    // raw, merged arrays, size in bytes
        lsblk.waitForFinished(5000);

        const QByteArray output = lsblk.readAll();
        m_lsblkEntries = LsblkOutputParser::parse(output);
    }

    std::vector<LsblkOutputParser::LsblkEntry> m_lsblkEntries;
};


SystemUtilitiesFactory::SystemUtilitiesFactory()
    : m_state(std::make_unique<State>())
{

}


SystemUtilitiesFactory::~SystemUtilitiesFactory()
{

}


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<LinuxDiskCollector>(m_state->m_lsblkEntries);
}


std::unique_ptr<IProbe> SystemUtilitiesFactory::generalAnalyzer()
{
    return std::make_unique<LinGeneralAnalyzer>(m_state->m_lsblkEntries);
}
