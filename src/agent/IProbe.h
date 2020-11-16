#pragma once
#include <iostream>

class IProbe
{
public:
    enum class HealthStatus
    {
        UNKNOWN = 0,
        GOOD,
        BAD,
        CHECK_STATUS
    };

    virtual HealthStatus GetStatus() = 0;
    virtual std::string GetRawData() = 0;
};