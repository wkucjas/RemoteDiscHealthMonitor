#include "DiskInfo.h"



	DiskInfo::DiskInfo()
	{
	}

	DiskInfo::DiskInfo(std::string _name, GeneralHealth::Health _health, SmartData _smartData)
		: m_name(_name), m_health(_health), m_smart(_smartData)
	{
	}

	void DiskInfo::SetName(const std::string& _name)
	{
		m_name = _name;
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

	void DiskInfo::SetSmart(const SmartData& _smartData)
	{
		m_smart = _smartData;
	}

	SmartData DiskInfo::GetSmart() const
	{
		return m_smart;
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

	//DiskInfo& operator=(const DiskInfo& _other)
	//{

	//}



	//std::ostream& operator<<(std::ostream& _out, const DiskInfo& _di)
	//{
	//	_out << _di.m_name.c_str() << _di.m_health;
	//	return _out;
	//}

