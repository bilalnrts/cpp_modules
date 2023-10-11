#include "whatever.hpp"

int main()
{
	//----CASE 1----
	int val1 = 42;
	int val2 = 21;

	swap(val1, val2);
	std::cout << "val1 : " << val1 << std::endl;
	std::cout << "val2 : " << val2 << std::endl;
	std::cout << "min : " << min(val1, val2) << std::endl;
	std::cout << "max : " << max(val1, val2) << std::endl;
	//----CASE 2----
	// char val1 = 'a';
	// char val2 = 'z';

	// swap(val1, val2);
	// std::cout << "val1 : " << val1 << std::endl;
	// std::cout << "val2 : " << val2 << std::endl;
	// std::cout << "min : " << min(val1, val2) << std::endl;
	// std::cout << "max : " << max(val1, val2) << std::endl;
	//----CASE 3----
	// std::string val1 = "String";
	// std::string val2 = "Char array";

	// swap(val1, val2);
	// std::cout << "val1 : " << val1 << std::endl;
	// std::cout << "val2 : " << val2 << std::endl;
	// std::cout << "min : " << min(val1, val2) << std::endl;
	// std::cout << "max : " << max(val1, val2) << std::endl;
}
