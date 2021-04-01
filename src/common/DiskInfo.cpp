#include "DiskInfo.h"



	DiskInfo::DiskInfo()
	{
	}

	DiskInfo::DiskInfo(std::string _name, GeneralHealth::Health& _health)
		: m_name(_name), m_health(_health)
	{
	}

	void DiskInfo::SetName(const std::string& _name)
	{
		m_name = _name;
	}

	void DiskInfo::SetProbesStatuses(const std::vector<ProbeStatus>& statuses)
    {
        m_statuses = statuses;
    }


	std::string DiskInfo::GetName() const
	{
		return m_name;
	};

	void DiskInfo:: SetHealth(const GeneralHealth::Health& _health)
	{
		m_health = _health;
	}

	GeneralHealth::Health DiskInfo:: GetHealth() const
	{
		return m_health;
	}

	const std::vector<ProbeStatus> & DiskInfo::GetProbesStatuses() const
    {
        return m_statuses;
    }

	bool DiskInfo::operator== (const DiskInfo& _other) const
	{
		if (this->m_health == _other.m_health
			&& this->m_name == _other.m_name)
		{
			return true;
		}
		return false;
	}

	bool DiskInfo::operator<(const DiskInfo&)const {
		return true; // for simplicity
	}


