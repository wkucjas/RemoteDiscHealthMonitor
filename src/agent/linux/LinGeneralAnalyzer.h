
#pragma once

#include <QStringList>

#include "../IProbe.h"
#include "LinuxDiskCollector.h"


class IPartitionsManager;

class LinGeneralAnalyzer : public IProbe
{
public:
    LinGeneralAnalyzer(const std::vector<LsblkOutputParser::LsblkEntry>& lsblkEntries);

    GeneralHealth::Health GetStatus(const Disk& disk) override;
    std::string GetRawData(const Disk& disk) override;

private:
    std::map<Disk, std::set<QString>> m_errors;
    LinuxDiskCollector m_diskCollector;

    void refreshState();
};
