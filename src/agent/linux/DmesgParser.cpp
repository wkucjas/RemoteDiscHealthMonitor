
#include <QRegularExpression>

#include "common/OutputParsersUtils.h"
#include "DmesgParser.h"
#include "IPartitionsManager.h"


namespace
{
    const QStringList ErrorPatterns = {
        "Buffer I/O error on device ([a-z0-9]*)"
    };
}


DmesgParser::DmesgParser(std::shared_ptr<IPartitionsManager> manager)
    : m_paritionsManager(manager)
{
}


std::map<Disk, std::set<QString>> DmesgParser::parse(const QByteArray& output) const
{
    std::map<Disk, std::set<QString>> errors;

    const auto lines = ParsersUtils::clean(output);

    for(const QString& line: lines)
        for(const QString& errorPattern: ErrorPatterns)
        {
            QRegularExpression errorRegex(errorPattern);

            if (line.contains(errorRegex))
            {
                const QRegularExpressionMatch errorMatch = errorRegex.match(line);
                const QString dev = errorMatch.captured(1);
                const QString physicalDev = m_paritionsManager->isPartition(dev)?
                                            m_paritionsManager->diskForPartition(dev):
                                            dev;

                const Disk disk(physicalDev.toStdString());

                errors[disk].insert(line);
            }
        }

    return errors;
}
