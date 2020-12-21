#pragma once

#include <string>

class Disk
{
public:
    Disk() = default;
    Disk(const std::string& _caption, const std::string& _deviceId, const std::string& _model,  const int& _partitions, const long long& _size);

private:
    std::string caption;
    std::string deviceId;
    std::string model;
    int partitions;
    long long size;
};
