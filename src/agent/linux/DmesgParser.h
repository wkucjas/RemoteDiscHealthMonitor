
#ifndef DMESGPARSER_H
#define DMESGPARSER_H

#include <QByteArray>
#include <QString>
#include <map>
#include <set>

#include <agent/Disk.h>


class IPartitionsManager;


class DmesgParser
{
public:
    DmesgParser(const IPartitionsManager &);

    std::map<Disk, std::set<QString>> parse(const QByteArray &) const;    // parse dmesg output and return found problems for disks

private:
    const IPartitionsManager& m_paritionsManager;
};

#endif // DMESGPARSER_H
