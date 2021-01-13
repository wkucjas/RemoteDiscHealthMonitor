
#pragma once

class IPartitionsManager
{
    virtual bool isPartition(const QString& deviceName) = 0;
    virtual QString diskForPartition(const QString& deviceName) = 0;
};
