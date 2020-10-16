#pragma once

#include <string>

class ISmartReader;

class HealthChecker
{
public:
    HealthChecker(ISmartReader &);

	std::string CheckDiscHealth();

public:
    ISmartReader& m_smartReader;
};
