#pragma once

#include <string>
#include "GeneralHealth.h"
#include "SmartData.h"

class DiskInfo
{
public:

	DiskInfo()
	{
	}

	std::string m_name;
	GeneralHealth::Health m_health;
	SmartData m_smart;

};