
#include <QDebug>
#include <QProcess>

#include "common/OutputParsersUtils.h"
#include "LinuxDiskCollector.h"
#include "LsblkOutputParser.h"


LinuxDiskCollector::LinuxDiskCollector(const std::vector<LsblkOutputParser::LsblkEntry>& lsblkEntries)
    : m_lsblkEntries(lsblkEntries)
{

}


std::vector<Disk> LinuxDiskCollector::GetDisksList()
{
    std::vector<Disk> disks;

    for (const auto& entry: m_lsblkEntries)
    {
        const Disk disk(entry.name.toStdString());

        disks.push_back(disk);
    }

    return disks;
}


bool LinuxDiskCollector::isPartition(const QString& deviceName) const
{
    for(const auto& entry: m_lsblkEntries)
        for(const QString& partitionDevice: entry.partitions)
            if (partitionDevice == deviceName)
                return true;

    return false;
}


QString LinuxDiskCollector::diskForPartition(const QString& deviceName) const
{
    for(const auto& entry: m_lsblkEntries)
        for(const QString& partitionDevice: entry.partitions)
            if (partitionDevice == deviceName)
                return entry.name;

    return {};
}

