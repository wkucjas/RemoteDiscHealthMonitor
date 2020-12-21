#include "Disk.h"

Disk::Disk(const std::string& _caption, const std::string& _deviceId, const std::string& _model, const int& _partitions, const long long& _size)
    : caption(_caption), deviceId(_deviceId), model(_model), partitions(_partitions), size(_size)
{
}