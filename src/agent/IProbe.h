#pragma once
#include <iostream>

class IProbe
{
public:
    virtual bool GetStatus() = 0;
    virtual std::string GetRawData() = 0;
};