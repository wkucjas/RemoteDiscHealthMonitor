#pragma once

#include <gmock/gmock.h>

#include "IProbe.h"

class IProbeMock : public IProbe
{
public:
    MOCK_METHOD(GeneralHealth::Health, GetStatus, (), (override));
    MOCK_METHOD(std::string, GetRawData, (), (override));
};