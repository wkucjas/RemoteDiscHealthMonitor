
#pragma once

#include <string>
#include "GeneralHealth.h"
#include "SmartData.h"
#include "ProbeStatus.h"

class DiskInfo
{
public:
	DiskInfo();

	DiskInfo(QString _name, GeneralHealth::Health& _health, const std::vector<ProbeStatus> &);

	void SetHealth(const GeneralHealth::Health& _health);
	void SetName(const QString& _name);
    void SetProbesStatuses(const std::vector<ProbeStatus> &);

	const QString& GetName() const;
	GeneralHealth::Health GetHealth() const;
    const std::vector<ProbeStatus>& GetProbesStatuses() const;

	auto operator<=>(const DiskInfo& _other) const = default;

private:
	QString m_name;
	GeneralHealth::Health m_health;
    std::vector<ProbeStatus> m_statuses;
};


Q_DECLARE_METATYPE(DiskInfo)


