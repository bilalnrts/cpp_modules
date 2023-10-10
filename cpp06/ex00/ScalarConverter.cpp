#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &another)
{
	std::cout << "Copy constructor called !" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &another)
{
	std::cout << "Operator overload called !" << std::endl;
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	toChar(str);
	toInt(str);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		handlePseudo(str);
	else
	{
		if (str[str.size() - 1] == 'f') {
			str = str.substr(0, str.size() - 1);
		}
		toFloat(str);
		toDouble(str);
	}
}

void	ScalarConverter::handlePseudo(std::string str)
{
	if (str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void	ScalarConverter::toChar(std::string str)
{
	int	i;
	char c;
	std::stringstream ss(str);
	ss >> i;
	if (!ss.fail()) {
		if (i <= 127 && i >= 0) {
			c = static_cast<char>(i);
			if (c < 32 || c > 126) {
				std::cout << "char: Non displayable" << std::endl;
			} else {
				std::cout << "char: '" << c << "'" << std::endl;
			}
		} else {
		std::cout << "char: impossible" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
}

void	ScalarConverter::toInt(std::string str)
{
	int					i;
	std::stringstream	ss(str);

	ss >> i;
	if (!ss.fail()) {
		i = static_cast<int>(std::stoi(str));
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
}

void	ScalarConverter::toFloat(std::string str)
{
	float				f;
	std::stringstream	ss(str);

	ss >> f;
	if (!ss.fail()) {
		f = static_cast<float>(std::stof(str));
		if (f - static_cast<int>(f) == 0) {
			std::cout << "float: " << f << ".0f" << std::endl;
		} else {
			std::cout << "float: " << f << "f" << std::endl;
		}
	} else {
		std::cout << "float: impossible" << std::endl;
	}
}

void	ScalarConverter::toDouble(std::string str)
{
	double				d;
	std::stringstream	ss(str);

	ss >> d;
	if (!ss.fail()) {
		d = static_cast<double>(std::stod(str));
		if (d - static_cast<int>(d) == 0) {
			std::cout << "double: " << d << ".0" << std::endl;
		} else {
			std::cout << "double: " << d << std::endl;
		}
	} else {
		std::cout << "double: impossible" << std::endl;
	}
}
