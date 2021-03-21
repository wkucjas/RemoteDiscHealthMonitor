#pragma once

#include "common/GeneralHealth.h"
#include "agent/Disk.h"


class CMDCommunication
{
public:
	GeneralHealth CollectDiskStatus(const Disk& _disk);

	bool CompareDeviceIdWithInstanceName(const Disk& _disk, std::string _instanceName);

private:
	std::string ExecuteDiscStatusCommand(const Disk& _disk) const;
	std::string GetInstanceName(const Disk& _disk) const;
	void ChangeStringToLowerCase(std::string& _string) const;

	GeneralHealth m_generalHealth;

};