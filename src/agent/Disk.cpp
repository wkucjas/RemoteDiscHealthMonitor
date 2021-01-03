#include "Disk.h"

Disk::Disk(const std::string& _caption, const std::string& _deviceId, const std::string& _model, const int& _partitions, const long long& _size)
    : m_caption(_caption)
    , m_deviceId(_deviceId)
    , m_model(_model)
    , m_partitions(_partitions)
    , m_size(_size)
{
}


const std::string& Disk::caption() const
{
    return m_caption;
}

const std::string& Disk::deviceId() const
{
    return m_deviceId;
}

const std::string& Disk::model() const
{
    return m_model;
}