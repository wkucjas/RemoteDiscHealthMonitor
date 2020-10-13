#pragma once

#include "ISmartReader.h"

class SmartReaderFactory
{
public:

	std::unique_ptr<ISmartReader> GetSMARTReader();
};
