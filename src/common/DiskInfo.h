
#pragma once

#include <string>
#include "GeneralHealth.h"
#include "SmartData.h"


class DiskInfo
{
public:

	DiskInfo();

	DiskInfo(std::string _name, GeneralHealth::Health _health, SmartData _smartData);

	void SetName(const std::string& _name);

	std::string GetName() const;

	void SetHealth(const GeneralHealth::Health& _health);

	GeneralHealth::Health GetHealth() const;

	void SetSmart(const SmartData& _smartData);

	SmartData GetSmart() const;


	bool operator== (const DiskInfo& _other) const;
	

	bool operator<(const DiskInfo&)const;

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
	SmartData m_smart;

};


Q_DECLARE_METATYPE(DiskInfo)


