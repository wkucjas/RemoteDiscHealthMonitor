#pragma once

#include "DiskInfo.h"
#include "SmartDataSerialize.h"
#include <QDataStream>

inline QDataStream& operator<<(QDataStream& _out, const DiskInfo& _diskInfo)
{
	_out << _diskInfo.GetName().c_str() << static_cast<qint8>(_diskInfo.GetHealth()) << _diskInfo.GetSmart();
	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, DiskInfo& _diskInfo)
{
	char* name;
	GeneralHealth::Health health;
	SmartData smartData;
	
	_in >> name >> health >> smartData;
	_diskInfo = DiskInfo(name, health, smartData);
	return _in;
}

inline QDataStream& operator<<(QDataStream& _out, const std::vector<DiskInfo>& _diskInfoVec) 
{
	_out << static_cast<quint32>(_diskInfoVec.size());
	for (auto& singleVal : _diskInfoVec)
	{
		_out << singleVal;
	}
	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, std::vector<DiskInfo>& _diskInfoVec)
{
	quint32 vecSize;
	char* name;
	GeneralHealth::Health health;
	SmartData smartData;
	_diskInfoVec.clear();
	_in >> vecSize;
	_diskInfoVec.reserve(vecSize);
	DiskInfo tempVal;
	while (vecSize--) {
		_in >> name >> health >> smartData;
		_diskInfoVec.push_back(DiskInfo(name, health, smartData));
	}
	return _in;
}