
#include <QDebug>
#include <QProcess>

#include "common/OutputParsersUtils.h"
#include "LinuxDiskCollector.h"
#include "LsblkOutputParser.h"


LinuxDiskCollector::LinuxDiskCollector()
{
    QProcess lsblk;

    lsblk.start("lsblk", { "-rMb" }, QProcess::ReadOnly);    // raw, merged arrays, size in bytes
    lsblk.waitForFinished(5000);

    const QByteArray output = lsblk.readAll();
    m_lsblkEntries = LsblkOutputParser::parse(output);
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


bool LinuxDiskCollector::isPartition(const QString& deviceName)
{
    for(const auto& entry: m_lsblkEntries)
        for(const QString& partitionDevice: entry.partitions)
            if (partitionDevice == deviceName)
                return true;

    return false;
}


QString LinuxDiskCollector::diskForPartition(const QString& deviceName)
{
    for(const auto& entry: m_lsblkEntries)
        for(const QString& partitionDevice: entry.partitions)
            if (partitionDevice == deviceName)
                return entry.name;

    return {};
}

