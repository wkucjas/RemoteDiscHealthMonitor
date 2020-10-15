
#include <iostream>

#include "HealthChecker.h"
#include "SmartReader.h"

int main(void)
{
    SmartReader smartReader;
	HealthChecker checker(smartReader);

	std::string health = checker.CheckDiscHealth();

	std::cout << health;

	return 0;
}
