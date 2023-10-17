#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

std::map<std::string, double>	readDatabase();
void							findCloserDate(std::map<std::string, double> lineList, std::string date, double val);
bool							checkFloat(std::string value);
bool							checkDate(std::string date);
bool							isLeap(int year);
bool							isValidDate(int d, int m, int y);

#endif
