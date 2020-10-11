#pragma once
#include <memory>
#include <string>

class SmartReader
{
public:

	SmartReader();
	std::unique_ptr<SmartReader> GetProperSMARTReader();
	virtual std::string ReadSMARTData();

};