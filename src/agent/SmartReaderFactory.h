#pragma once

#include "SmartReader.h"

class SmartReaderFactory
{
public:

	std::unique_ptr<SmartReader> GetSMARTReader();
};
