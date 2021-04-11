
#include <QProcess>

#include "../SystemUtilitiesFactory.h"
#include "LinuxDiskCollector.h"
#include "LinGeneralAnalyzer.h"
#include "LsblkOutputParser.h"


namespace
{
    class LinuxDiskCollectorWrapper: public IDiskCollector
    {
        public:
            LinuxDiskCollectorWrapper(std::shared_ptr<IDiskCollector> collector)
                : m_collector(collector)
            {

            }

            std::vector<Disk> GetDisksList() override
            {
                return m_collector->GetDisksList();
            }

        private:
            std::shared_ptr<IDiskCollector> m_collector;
    };
}


struct SystemUtilitiesFactory::State
{
    State()
    {
        QProcess lsblk;

        lsblk.start("lsblk", { "-rMb" }, QProcess::ReadOnly);    // raw, merged arrays, size in bytes
        lsblk.waitForFinished(5000);

        const QByteArray output = lsblk.readAll();
        const auto diskData = LsblkOutputParser::parse(output);

        m_diskCollector = std::make_unique<LinuxDiskCollector>(diskData);
    }

    std::shared_ptr<LinuxDiskCollector> m_diskCollector;
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
    return std::make_unique<LinuxDiskCollectorWrapper>(m_state->m_diskCollector);
}


std::vector<std::unique_ptr<IProbe>> SystemUtilitiesFactory::getProbes()
{
    std::vector<std::unique_ptr<IProbe>> probes;
    probes.emplace_back(std::make_unique<LinGeneralAnalyzer>(m_state->m_diskCollector));

    return probes;
}
