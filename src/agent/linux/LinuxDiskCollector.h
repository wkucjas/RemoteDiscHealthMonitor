
#pragma once

#include <QString>

#include "../IDiskCollector.h"
#include "IPartitionsManager.h"
#include "LsblkOutputParser.h"


class LinuxDiskCollector: public IDiskCollector, public IPartitionsManager
{
public:
    LinuxDiskCollector();

    std::vector<Disk> GetDisksList() override;

    bool isPartition(const QString & deviceName) override;
    QString diskForPartition(const QString & deviceName) override;

private:
    std::vector<LsblkOutputParser::LsblkEntry> m_lsblkEntries;
};
