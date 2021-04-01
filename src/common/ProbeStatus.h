
#pragma once

#include <QDataStream>
#include <QVariant>

#include "agent/IProbe.h"
#include "SmartDataSerialize.h"


struct ProbeStatus
{
    GeneralHealth::Health health;
    IProbe::RawData rawData;
};

inline QDataStream& operator<<(QDataStream& _out, const ProbeStatus& _probeStatus)
{
    static_assert(std::variant_size_v<IProbe::RawData> == 2, "Streaming operator prepared for two types in RawData variant");

    const qint8 rawDataType = _probeStatus.rawData.index();

	_out << static_cast<qint8>(_probeStatus.health);
    _out << static_cast<qint8>(rawDataType);

    switch (rawDataType)
    {
        case 0:
            _out << QString::fromStdString(std::get<0>(_probeStatus.rawData));
            break;

        case 1:
            _out << std::get<1>(_probeStatus.rawData);
            break;
    }

	return _out;
}

inline QDataStream& operator>>(QDataStream& _in, ProbeStatus& _probeStatus)
{
    static_assert(std::variant_size_v<IProbe::RawData> == 2, "Streaming operator prepared for two types in RawData variant");

    qint8 health;
    qint8 rawDataType = 0;

	_in >> health >> rawDataType;

    _probeStatus.health = static_cast<GeneralHealth::Health>(health);

    switch (rawDataType)
    {
        case 0:
        {
            QString stringData;

            _in >> stringData;
            _probeStatus.rawData = stringData.toStdString();
            break;
        }

        case 1:
        {
            SmartData smartData;

            _in >> smartData;
            _probeStatus.rawData = smartData;
            break;
        }

        default:
            assert(!"unexpected type");
    }

	return _in;
}
