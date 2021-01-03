#pragma once

#include "common/GeneralHealth.h"
#include "agent/Disk.h"


class CMDCommunication
{
public:
	GeneralHealth CollectDiskStatus(const Disk& _disk);

private:
	std::string ExecuteDiscStatusCommand(const Disk& _disk) const;

	GeneralHealth m_generalHealth;

};