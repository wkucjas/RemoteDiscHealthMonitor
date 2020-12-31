
#pragma once

#include <QString>

class LsblkOutputParser
{
public:
    struct LsblkEntry
    {
        QString name;
        int major;
        int minor;
        int rm;
        QString size;
        bool ro;
        QString type;
        QString mountpoint;
    };

    static std::vector<LsblkEntry> parse(const QByteArray& output);
};
