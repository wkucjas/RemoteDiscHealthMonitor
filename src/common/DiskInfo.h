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

	std::string GetName() const
	{
		return m_name;
	};

	void SetHealth(const GeneralHealth::Health& _health)
	{
		m_health = _health;
	}

	GeneralHealth::Health GetHealth() const
	{
		return m_health;
	}

	//void SetSmart(const SmartData& _smartData)
	//{
	//	m_smart = _smartData;
	//}

	//SmartData GetSmart()
	//{
	//	return m_smart;
	//}

	bool operator== (const DiskInfo& _other)
	{
		if (this->m_health == _other.m_health
			&& this->m_name == _other.m_name)
		{
			return true;
		}
		return false;
	}

	//DiskInfo& operator=(const DiskInfo& _other)
	//{

	//}



	//std::ostream& operator<<(std::ostream& _out, const DiskInfo& _di)
	//{
	//	_out << _di.m_name.c_str() << _di.m_health;
	//	return _out;
	//}


private:
	std::string m_name;
	GeneralHealth::Health m_health;
	//SmartData m_smart;

};

Q_DECLARE_METATYPE(DiskInfo)
