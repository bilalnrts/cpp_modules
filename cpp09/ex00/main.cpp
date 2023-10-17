#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream					file(av[1]);
		std::map<std::string, double>	lineList;
		std::string						line;
		std::string						date;
		std::string						value;

		if (file.is_open()) {
			lineList = readDatabase();
			getline(file, line);
			while (getline(file, line))
			{
				std::stringstream ss(line);
				if (getline(ss, date, '|') && getline(ss, value)) {
					date.erase(date.find_last_not_of(" \t") + 1);
					double val = std::atof(value.c_str());
					if (val < 0) {
						std::cout << "Error : not a positive number" << std::endl;
					} else if (val > 1000) {
						std::cout << "Error : too large a number." << std::endl;
					} else if (!checkFloat(value)) {
						std::cout << "Error : bad value input." << std::endl;
					} else if (!checkDate(date)) {
						std::cout << "Error : bad date input." << std::endl;
					} else {
						if (lineList.find(date) != lineList.end()) {
							std::cout << date << " => " << val << " = " << val * lineList.at(date) << std::endl;
						} else {
							findCloserDate(lineList, date, val);
						}
					}
				} else {
					std::cout << "Error : bad input => " << date << std::endl;
				}
			}
			file.close();
		} else {
			std::cout << "Error : couldn't open file !" << std::endl;
			return (-1);
		}
	} else {
		std::cout << "Wrong number of argument !" << std::endl;
		return (-1);
	}
	return (1);
}
