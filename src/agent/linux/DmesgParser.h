
#ifndef DMESGPARSER_H
#define DMESGPARSER_H

#include <map>
#include <memory>
#include <set>
#include <QByteArray>
#include <QString>

#include <agent/Disk.h>


class IPartitionsManager;


class DmesgParser
{
public:
    DmesgParser(std::shared_ptr<IPartitionsManager>);

    std::map<Disk, std::set<QString>> parse(const QByteArray &) const;    // parse dmesg output and return found problems for disks

private:
    std::shared_ptr<IPartitionsManager> m_paritionsManager;
};

#endif // DMESGPARSER_H
