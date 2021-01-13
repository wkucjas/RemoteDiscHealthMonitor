
#pragma once

class IPartitionsManager
{
public:
    virtual ~IPartitionsManager() = default;

    virtual bool isPartition(const QString& deviceName) = 0;
    virtual QString diskForPartition(const QString& deviceName) = 0;
};
