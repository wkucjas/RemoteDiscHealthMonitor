#pragma once

#include "DiskInfo.h"
#include <QDataStream>

QDataStream& operator<<(QDataStream& out, DiskInfo& _diskInfo)
{
	out << _diskInfo.GetName().c_str() << static_cast<qint8>(_diskInfo.GetHealth());
	return out;
}

QDataStream& operator>>(QDataStream& in, DiskInfo& _diskInfo)
{
	char* name;
	GeneralHealth::Health health;
	
	in >> name >> health;
	_diskInfo = DiskInfo(name, health);
	return in;
}