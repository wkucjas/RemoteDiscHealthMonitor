
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

    qDebug() << output;

    const auto lsblkEntries = LsblkOutputParser::parse(output);

    for (const auto entry: lsblkEntries)
    {
        const QString model = entry.type == "disk"? modelFor(entry.name): QString();

        const Disk disk(entry.name.toStdString(),
                        QString("%1:%2").arg(entry.major).arg(entry.minor).toStdString(),
                        model.toStdString(),
                        entry.partitions,
                        entry.size);

        disks.push_back(disk);
    }

    return disks;
}


QString LinuxDiskCollector::modelFor(const QString& device) const
{
    const QString modelNumber = "Model Number:";

    QProcess hdparm;
    hdparm.start("hdparm", { "-I", QString("/dev/%1").arg(device) }, QProcess::ReadOnly);
    hdparm.waitForFinished(5000);

    const QByteArray output = hdparm.readAll();
    const QStringList entries = ParsersUtils::clean(output);

    auto it = std::find_if(entries.begin(), entries.end(), [modelNumber](const QString& line) {
        return line.startsWith(modelNumber);
    });

    QString model;

    if (it != entries.end())
    {
        const QString simplified = it->simplified();
        model = simplified.mid(modelNumber.length() + 1);
    }

    return model;
}
