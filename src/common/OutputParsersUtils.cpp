
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

        QStringList trimList(QStringList list)
        {
            while(list.isEmpty() == false && list.first().isEmpty())
                list.removeFirst();

            while(list.isEmpty() == false && list.last().isEmpty())
                list.removeLast();

            return list;
        }
    }


    QStringList clean(const QByteArray& bytes)
    {
        const QString output(bytes);
        const auto lines = output.split('\n');
        const auto cleanLines = cleanup(lines);
        const auto trimmed = trimList(cleanLines);

        return trimmed;
    }
}
