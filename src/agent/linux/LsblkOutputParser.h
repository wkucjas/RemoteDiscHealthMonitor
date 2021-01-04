
#pragma once

#include <QString>

class LsblkOutputParser
{
public:
    struct LsblkEntry
    {
        QString name;
        QString type;
        std::uint64_t size;
        int partitions;
        int major;
        int minor;

        friend auto operator==(const LsblkEntry& lhs, const LsblkEntry& rhs)
        {
            return std::tie(lhs.name, lhs.type, lhs.size, lhs.partitions, lhs.major, lhs.minor) ==
                   std::tie(rhs.name, rhs.type, rhs.size, rhs.partitions, rhs.major, rhs.minor);
        }
    };

    static std::vector<LsblkEntry> parse(const QByteArray& output);
};
