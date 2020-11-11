
#ifndef MANUALAGENTSVALIDATOR_H
#define MANUALAGENTSVALIDATOR_H

#include <qobject.h>


class ManualAgentsValidator : public QObject
{
    Q_OBJECT

    public:

    public slots:
        void addNewAgent(const QString& name, const QString& ip, const QString& port);
};

#endif // MANUALAGENTSVALIDATOR_H
