#include "Harl.hpp"

int main()
{
	Harl	harl;

	std::cout << "Debug : " << std::endl;
	harl.complain("DEBUG");
	std::cout << "Warning : " << std::endl;
	harl.complain("WARNING");
	std::cout << "Info : " << std::endl;
	harl.complain("INFO");
	std::cout << "Error: " << std::endl;
	harl.complain("ERROR");
	return 0;
}
