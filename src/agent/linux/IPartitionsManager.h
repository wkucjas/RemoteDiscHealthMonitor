
#pragma once

class IPartitionsManager
{
public:
    virtual ~IPartitionsManager() = default;

    virtual bool isPartition(const QString& deviceName) const = 0;
    virtual QString diskForPartition(const QString& deviceName) const = 0;
};
