
#pragma once

#include <gmock/gmock.h>

#include "linux/IPartitionsManager.h"

class IPartitionsManagerMock: public IPartitionsManager
{
public:
    MOCK_METHOD(bool, isPartition, (const QString &), (const, override));
    MOCK_METHOD(QString, diskForPartition, (const QString &), (const, override));
};
