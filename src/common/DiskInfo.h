
#pragma once

#include <string>
#include "GeneralHealth.h"
#include "SmartData.h"


class DiskInfo
{
public:

	DiskInfo();

	DiskInfo(std::string _name, GeneralHealth::Health& _health);

	void SetName(const std::string& _name);

	std::string GetName() const;

	void SetHealth(const GeneralHealth::Health& _health);

	GeneralHealth::Health GetHealth() const;


	bool operator== (const DiskInfo& _other) const;

	bool operator<(const DiskInfo&)const;

private:
	std::string m_name;
	GeneralHealth::Health m_health;

};


Q_DECLARE_METATYPE(DiskInfo)


