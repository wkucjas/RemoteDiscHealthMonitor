#pragma once

#include <string>

class Disc
{
public:
    Disc();
    Disc(const std::string& _caption, const std::string& _deviceId, const std::string& _model,  const int& _partitions, const int& _size);

private:
    std::string caption;
    std::string deviceId;
    std::string model;
    int partitions;
    int size;
};
