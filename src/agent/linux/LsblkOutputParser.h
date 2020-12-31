
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

        friend auto operator<=>(const LsblkEntry &, const LsblkEntry &) = default;
    };

    static std::vector<LsblkEntry> parse(const QByteArray& output);
};
