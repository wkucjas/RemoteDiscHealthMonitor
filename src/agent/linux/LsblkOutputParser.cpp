
#include <QDebug>

#include "common/OutputParsersUtils.h"
#include "LsblkOutputParser.h"


namespace
{
    struct RawLsblkEntry
    {
        QString name;
        QString type;
        std::uint64_t size;
        int major;
        int minor;
    };

    RawLsblkEntry parseLine(const QString& line)
    {
        const QStringList cols = line.split(' ');
        assert(cols.size() >= 6);               // we expect at least 6 columns here

        const QStringList major_minor = cols[1].split(':');
        assert(major_minor.size() == 2);        // we expect two numbers - major and minor after separation

        const RawLsblkEntry rawEntry{
            .name = cols[0],
            .type = cols[5],
            .size = cols[3].toULongLong(),
            .major = major_minor[0].toInt(),
            .minor = major_minor[1].toInt()
        };

        return rawEntry;
    }

    LsblkOutputParser::LsblkEntry fromRaw(const RawLsblkEntry& raw)
    {
        const LsblkOutputParser::LsblkEntry entry {
            .name = raw.name,
            .type = raw.type,
            .size = raw.size,
            .partitions = 0,
            .major = raw.major,
            .minor = raw.minor
        };

        return entry;
    }
}


std::vector<LsblkOutputParser::LsblkEntry> LsblkOutputParser::parse(const QByteArray& output)
{
    std::vector<LsblkEntry> entries;

    QStringList lines = ParsersUtils::clean(output);
    lines.removeFirst();            // drop header

    while (lines.empty() == false)
    {
        const QString line = lines.takeFirst();
        const RawLsblkEntry entry = parseLine(line);

        if (entry.type == "disk")
            entries.push_back(fromRaw(entry));
        else if (entry.type == "part")
        {
            // check which disk should be upgraded
            auto entryIt = std::find_if(entries.begin(), entries.end(), [part_name = entry.name](const auto& disk) {
                return part_name.startsWith(disk.name);
            });

            if (entryIt == entries.end())
                qWarning() << QString("Partition %1 does not match any disk").arg(entry.name);
            else
                entryIt->partitions++;
        }
        else if (entry.type.left(4) == "raid")
            entries.push_back(fromRaw(entry));
        else
        {
            // unknown or uninteresting entry, drop it
        }
    }

    return entries;
}
