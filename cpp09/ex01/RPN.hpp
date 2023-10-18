#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

int		result(int value1, int value2, char c);
bool	isOperator(char c);
bool	isNumber(char c);
bool	isFullSpace(std::string arg);
bool	checkArguments(char **av);

#endif
