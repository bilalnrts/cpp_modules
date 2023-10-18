#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2) {
		if (checkArguments(av)) {
			std::string		args(av[1]);
			std::stack<int>	rpn;
			int				value1;
			int				value2;

			for (int i = 0; args[i]; i++) {
				if (isNumber(args[i])) {
					if (!isNumber(args[i + 1])) {
						rpn.push(args[i] - 48);
					} else {
						std::cout << "Error : Values must be between 0 and 9 !" << std::endl;
						return (-1);
					}
				} else if (isOperator(args[i])) {
					if (rpn.size() >= 2) {
						value1 = rpn.top();
						rpn.pop();
						value2 = rpn.top();
						rpn.pop();
						rpn.push(result(value1, value2, args[i]));
					} else {
						std::cout << "Error : Invalid syntax !";
						return (-1);
					}
				}
			}
			std::cout << rpn.top() << std::endl;
		} else {
			std::cout << "Error : Invalid argument !" << std::endl;
			return (-1);
		}
	} else {
		std::cout << "Error : Wrong number of arguments !" << std::endl;
		return (-1);
	}
}
