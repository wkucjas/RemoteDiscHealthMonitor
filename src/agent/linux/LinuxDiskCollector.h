
#pragma once

#include <QString>

#include "../IDiskCollector.h"
#include "IPartitionsManager.h"
#include "LsblkOutputParser.h"


class LinuxDiskCollector: public IDiskCollector, public IPartitionsManager
{
public:
    LinuxDiskCollector(const std::vector<LsblkOutputParser::LsblkEntry>& lsblkEntries);

    std::vector<Disk> GetDisksList() override;

    bool isPartition(const QString & deviceName) const override;
    QString diskForPartition(const QString & deviceName) const override;

private:
    std::vector<LsblkOutputParser::LsblkEntry> m_lsblkEntries;
};
