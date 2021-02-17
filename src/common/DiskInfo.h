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

	DiskInfo(std::string _name, GeneralHealth::Health _health)
		: m_name(_name), m_health(_health)
	{
	}

	void SetName(const std::string& _name)
	{
		m_name = _name;
	}

	std::string GetName()
	{
		return m_name;
	};

	void SetHealth(const GeneralHealth::Health& _health)
	{
		m_health = _health;
	}

	GeneralHealth::Health GetHealth()
	{
		return m_health;
	}

private:
	std::string m_name;
	GeneralHealth::Health m_health;
	SmartData m_smart;

};
