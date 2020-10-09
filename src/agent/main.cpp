#include <iostream>

#include <memory>
#include "HealthChecker.h"




int main(void)
{

	HealthChecker checker;
	
	std::string health = checker.CheckDiscHealth();

	std::cout << health;

	return 0;
}
