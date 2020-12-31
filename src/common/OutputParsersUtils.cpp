
#include "OutputParsersUtils.h"

namespace ParsersUtils
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
    }

    QStringList clean(const QByteArray& bytes)
    {
        const QString output(bytes);
        const auto lines = output.split('\n');
        const auto cleanLines = cleanup(lines);

        return cleanLines;
    }
}
