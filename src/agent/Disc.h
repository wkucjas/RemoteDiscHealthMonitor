#pragma once

#include <string>

class Disc
{
public:
    Disc();
    Disc(std::string _caption, std::string _deviceId, std::string _model, int _partitions, int _size);

private:
    std::string caption;
    std::string deviceId;
    std::string model;
    int partitions;
    int size;
};
