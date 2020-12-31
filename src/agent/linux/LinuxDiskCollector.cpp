
#include <QDebug>
#include <QProcess>

#include "LinuxDiskCollector.h"
#include "LsblkOutputParser.h"


std::vector<Disk> LinuxDiskCollector::GetDisksList()
{
    QProcess lsblk;

    lsblk.start("lsblk", { "-rMb" }, QProcess::ReadOnly);    // raw, merged arrays, size in bytes
    lsblk.waitForFinished(5000);
    const QByteArray output = lsblk.readAll();

    qDebug() << output;

    LsblkOutputParser::parse(output);

    return {};
}
