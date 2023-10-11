#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter &operator=(const ScalarConverter &another);

	public:
		static void convert(std::string str);
		static void handlePseudo(std::string str);
		static void toInt(std::string str);
		static void toChar(std::string str);
		static void toFloat(std::string str);
		static void toDouble(std::string str);
};

#endif
