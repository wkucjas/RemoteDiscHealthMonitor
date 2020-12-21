
#include <QStringList>

#include "SmartCtlOutputParser.h"


namespace SmartCtlOutputParser
{

    namespace
    {
        QStringList cleanup(const QStringList& list)
        {
            QStringList clean;

            for(const QString& entry: list)
                clean.append(entry.trimmed());

            return clean;
        }

        QStringList smartAttributes(const QStringList& output)
        {
            QStringList attributes;

            auto it = output.constBegin();

            // skip all lines before attributes table
            for(; it != output.constEnd() && *it != "Vendor Specific SMART Attributes with Thresholds:"; ++it);

            // skip table header
            if (it != output.constEnd())
                ++it;

            if (it != output.constEnd())
                ++it;

            // copy table
            for(; it != output.constEnd() && *it != ""; ++it)
                attributes.append(*it);

            return attributes;
        }

        std::map<std::string, std::string> parseRawTable(const QStringList& table)
        {
            std::map<std::string, std::string> attributes;

            for(const QString& rawAttribute: table)
            {
                const QString rawAttributeSimplified = rawAttribute.simplified();   // drop all redundant spaces
                const QStringList rawAttributeSplitted = rawAttributeSimplified.split(' ');

                if (rawAttributeSplitted.size() == 10)  // 10 columns expected (ID# ATTRIBUTE_NAME FLAG VALUE WORST THRESH TYPE UPDATED WHEN_FAILED RAW_VALUE)
                {
                    const QString& name = rawAttributeSplitted[1];      // ATTRIBUTE_NAME
                    const QString& rawValue = rawAttributeSplitted[9];  // RAW_VALUE

                    attributes.emplace(name.toStdString(),
                                       rawValue.toStdString());
                }
            }

            return attributes;
        }
    }

    std::map<std::string, std::string> parse(const QByteArray& smartCtlOutput)
    {
        const QString output(smartCtlOutput);
        const auto lines = output.split('\n');
        const auto cleanLines = cleanup(lines);
        const auto attributeLines = smartAttributes(cleanLines);
        const std::map<std::string, std::string> table = parseRawTable(attributeLines);

        return table;
    }
}
