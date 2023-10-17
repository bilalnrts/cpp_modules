#include "BitcoinExchange.hpp"

std::map<std::string, double>	readDatabase()
{
	std::map<std::string, double>	lineList;
	std::string						line;
	std::string						value;
	std::string						date;
	std::ifstream					file("data.csv");

	if (file.is_open()) {
		getline(file, line);
		while (getline(file, line))
		{
			std::stringstream	ss(line);
			if (getline(ss, date, ',') && getline(ss, value))
				lineList[date] = atof(value.c_str());
		}
	} else {
		std::cout << "Error : couldn't open file !" << std::endl;
		exit(-1);
	}
	file.close();
	return (lineList);
}

bool	checkFloat(std::string value)
{
	std::stringstream	ss(value);
	float				val;
	ss >> val;
	if (!ss.fail()) {
		int i = value.find('.');
		if (i == -1 || value[i + 1] != '.')
			return (true);
		return (false);
	} else {
		return (false);
	}
}

bool isLeap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
	if ((y > 2022 || y < 2009) || (m < 1 || m > 12) || (d < 1 || d > 31))
		return false;
	if (m == 2) {
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);
	return true;
}

bool	checkDate(std::string date)
{
	std::stringstream 	ss(date);
	std::string			buffer;
	int					day;
	int					month;
	int					year;

	if (date.length() != 10)
		return (false);
	getline(ss, buffer, '-');
	year = stoi(buffer);
	getline(ss, buffer, '-');
	month = stoi(buffer);
	getline(ss, buffer, '-');
	day = stoi(buffer);
	return (isValidDate(day, month, year));
}

void	findCloserDate(std::map<std::string, double> lineList, std::string date, double val)
{
	std::map<std::string, double>::iterator it = lineList.lower_bound(date);
	if (it != lineList.begin())
		it--;
	std::cout << date << " => " << val << " = " << val * it->second << std::endl;
}


