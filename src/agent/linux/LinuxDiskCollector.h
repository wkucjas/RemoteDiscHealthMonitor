
#pragma once

#include <QString>

#include "../IDiskCollector.h"


class LinuxDiskCollector: public IDiskCollector
{
public:
    std::vector<Disk> GetDisksList() override;

private:
    QString modelFor(const QString& device) const;
};
