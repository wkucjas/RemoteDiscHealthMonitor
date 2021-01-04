
#include <QDebug>
#include <QProcess>

#include "common/OutputParsersUtils.h"
#include "LinuxDiskCollector.h"
#include "LsblkOutputParser.h"


std::vector<Disk> LinuxDiskCollector::GetDisksList()
{
    std::vector<Disk> disks;

    QProcess lsblk;

    lsblk.start("lsblk", { "-rMb" }, QProcess::ReadOnly);    // raw, merged arrays, size in bytes
    lsblk.waitForFinished(5000);

    const QByteArray output = lsblk.readAll();
    const auto lsblkEntries = LsblkOutputParser::parse(output);

    for (const auto& entry: lsblkEntries)
    {
        const Disk disk(entry.name.toStdString());

        disks.push_back(disk);
    }

    return disks;
}
