#pragma once

#include <memory>
#include "ISmartReader.h"

class SmartReaderFactory
{
public:
	std::unique_ptr<ISmartReader> GetSMARTReader();
};
