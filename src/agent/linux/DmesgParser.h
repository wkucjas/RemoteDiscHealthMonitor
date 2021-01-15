
#ifndef DMESGPARSER_H
#define DMESGPARSER_H

#include <map>
#include <memory>
#include <set>
#include <QByteArray>
#include <QString>

#include <agent/Disk.h>


class IPartitionsManager;


namespace DmesgParser
{
    std::map<Disk, std::set<QString>> parse(const QByteArray &, const IPartitionsManager &);    // parse dmesg output and return found problems for disks
}

#endif // DMESGPARSER_H
