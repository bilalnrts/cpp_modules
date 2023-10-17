#include "RPN.hpp"

bool	isFullSpace(std::string arg)
{
	for (int i = 0; i < arg.length(); i++) {
		if (arg[i] != ' ')
			return (false);
	}
	return (true);
}

bool	checkArguments(char **av)
{
	std::string	arg(av[1]);
	if (!av[1] || arg == "" || isFullSpace(arg))
		return (false);
	arg = arg.substr(arg.find_first_not_of(" \t"), arg.find_last_not_of(" \t") - arg.find_first_not_of(" \t") + 1);
	for (int i = 0; i < arg.length(); i++) {
		if (!isdigit(arg[i]) && arg[i] != ' ' && arg[i] != '+' && arg[i] != '-' && arg[i] != '*' && arg[i] != '/')
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	if (ac == 2) {
		if (checkArguments(av)) {
			std::cout << "Hello World !" << std::endl;
		} else {
			std::cout << "Error : Invalid argument !" << std::endl;
		}
	} else {
		std::cout << "Error : Wrong number of arguments !" << std::endl;
	}
}
