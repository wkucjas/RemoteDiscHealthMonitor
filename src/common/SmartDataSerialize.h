#pragma once

#include "SmartData.h"
#include <QDataStream>

inline QDataStream& operator<<(QDataStream& _out, const SmartData::AttrData& _attrData)
{
	_out << _attrData.status << _attrData.value << _attrData.worst << _attrData.rawVal << _attrData.rawVal2;

	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, SmartData::AttrData& _attrData)
{
	_in >> _attrData.status >> _attrData.value >> _attrData.worst >> _attrData.rawVal >> _attrData.rawVal2;
	return _in;
}

inline QDataStream& operator<<(QDataStream& _out, const SmartData& _smartData)
{
	_out << static_cast<quint32>(_smartData.smartData.size());
	for (auto& singleVal : _smartData.smartData)
	{
		_out << singleVal.first << singleVal.second;
	}
	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, SmartData& _smartData)
{
	quint32 mapSize;
	_in >> mapSize;
	std::pair<unsigned char, SmartData::AttrData> tempPair;

	while (mapSize--)
	{
		_in >> tempPair.first >> tempPair.second;
		_smartData.smartData.insert(tempPair);
	}
	return _in;
}

