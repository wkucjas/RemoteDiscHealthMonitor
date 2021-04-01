
#pragma once

#include <QDataStream>

#include "DiskInfo.h"
#include "SmartDataSerialize.h"
#include "ProbeStatusSerialize.h"


inline QDataStream& operator<<(QDataStream& _out, const DiskInfo& _diskInfo)
{
	_out << _diskInfo.GetName().c_str() << static_cast<qint8>(_diskInfo.GetHealth());

    const auto& statuses = _diskInfo.GetProbesStatuses();
    _out << static_cast<quint32>(statuses.size());
    for (const auto& probeStatus: statuses)
        _out << probeStatus;

	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, DiskInfo& _diskInfo)
{
	char* name;
	GeneralHealth::Health health;
    quint32 statusesCount = 0;
    std::vector<ProbeStatus> statuses;

	_in >> name >> health >> statusesCount;

    statuses.reserve(statusesCount);
    for(int i = 0; i < statusesCount; i++)
    {
        ProbeStatus status;
        _in >> status;
        statuses.push_back(status);
    }

	_diskInfo = DiskInfo(name, health, statuses);
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
	_diskInfoVec.clear();
	_in >> vecSize;
	_diskInfoVec.reserve(vecSize);
	DiskInfo tempVal;
	while (vecSize--) {
        DiskInfo diskInfo;
		_in >> diskInfo;
		_diskInfoVec.push_back(diskInfo);
	}
	return _in;
}
