#pragma once

#include "common/GeneralHealth.h"


class CMDCommunication
{
public:
	GeneralHealth CollectDiskStatus();

private:
	std::string ExecuteDiscStatusCommand() const;

	GeneralHealth m_generalHealth;

};