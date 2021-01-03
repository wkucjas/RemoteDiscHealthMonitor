#pragma once

#include <string>

class Disk
{
public:
    Disk() = default;
    Disk(const std::string& _caption, const std::string& _deviceId, const std::string& _model, const int& _partitions, const long long& _size);

    const std::string& caption() const;
    const std::string& deviceId() const;
    const std::string& model() const;

protected:
    std::string m_caption;
    std::string m_deviceId;
    std::string m_model;
    int m_partitions;
    std::uint64_t m_size;
};
