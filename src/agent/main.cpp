#include <iostream>

#include <memory>
#include "HealthChecker.h"




int main(void)
{

	std::unique_ptr<HealthChecker> healthyPointer(new HealthChecker());
	
	std::string health;

	healthyPointer->CheckDiscHealth(health);

	std::cout << health;

	return 0;
}
