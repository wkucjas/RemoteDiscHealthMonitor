#pragma once

#include <vector>
#include <string>

class IDiscCollector
{
public:

    virtual ~IDiscCollector() = default;
    virtual std::vector<std::string> GetDiscsList();
};
