#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR",
	};
	void	(Harl::*complains[4])();;
	complains[0] = &Harl::debug;
	complains[1] = &Harl::info;
	complains[2] = &Harl::warning;
	complains[3] = &Harl::error;

	int i = -1;
	while (++i < 4)
	{
		if (level == levels[i])
		{
			(this->*complains[i])();
			break ;
		}
	}
}
