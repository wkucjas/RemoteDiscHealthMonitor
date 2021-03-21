#pragma once

#include <gmock/gmock.h>

#include "IProbe.h"

class IProbeMock : public IProbe
{
public:
    MOCK_METHOD(GeneralHealth::Health, GetStatus, (const Disk&), (override));
    MOCK_METHOD(RawData, GetRawData, (const Disk&), (override));
};