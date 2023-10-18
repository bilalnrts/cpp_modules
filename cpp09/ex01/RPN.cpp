#include "RPN.hpp"

int	result(int value1, int value2, char c)
{
	if (c == '+') {
		return (value1 + value2);
	} else if (c == '-') {
		return (value2 - value1);
	} else if (c == '*') {
		return (value1 * value2);
	} else {
		return (value2 / value1);
	}
}

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	isNumber(char c)
{
	return (c <= '9' && c >= '0');
}

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
