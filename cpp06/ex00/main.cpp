#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (av[1])
		ScalarConverter::convert(av[1]);
	else
		std::cout << "Give me an argument!" << std::endl;
	return (0);
}
