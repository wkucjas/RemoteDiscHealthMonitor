
#pragma once

#include <string>
#include "GeneralHealth.h"
#include "SmartData.h"
#include "ProbeStatus.h"

class DiskInfo
{
public:
	DiskInfo();

	DiskInfo(std::string _name, GeneralHealth::Health& _health);

	void SetHealth(const GeneralHealth::Health& _health);
	void SetName(const std::string& _name);
    void SetProbesStatuses(const std::vector<ProbeStatus> &);

	std::string GetName() const;
	GeneralHealth::Health GetHealth() const;
    const std::vector<ProbeStatus>& GetProbesStatuses() const;

	auto operator<=>(const DiskInfo& _other) const = default;

private:
	std::string m_name;
	GeneralHealth::Health m_health;
    std::vector<ProbeStatus> m_statuses;
};


Q_DECLARE_METATYPE(DiskInfo)


