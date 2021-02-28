#pragma once

#include "DiskInfo.h"
#include <QDataStream>

inline QDataStream& operator<<(QDataStream& out, const DiskInfo& _diskInfo)
{
	out << _diskInfo.GetName().c_str() << static_cast<qint8>(_diskInfo.GetHealth());
	return out;
}

inline QDataStream& operator>>(QDataStream& in, DiskInfo& _diskInfo)
{
	char* name;
	GeneralHealth::Health health;
	
	in >> name >> health;
	_diskInfo = DiskInfo(name, health);
	return in;
}

