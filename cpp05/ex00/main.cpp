#include "Bureaucrat.hpp"

int main()
{
	// ********** CASE 1 *************
	try
	{
		Bureaucrat b("bilal", 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//********** CASE 2 *************
	// try
	// {
	// 	Bureaucrat b("bilal", 151);
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// ********** CASE 3 *************
	// try
	// {
	// 	Bureaucrat b("bilal", 1);
	// 	b.increment();
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// ********** CASE 4 *************
	// try
	// {
	// 	Bureaucrat b("bilal", 150);
	// 	b.decrement();
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// ********** CASE 5 *************
	// try
	// {
	// 	Bureaucrat b("bilal", 1);
	// 	std::cout << "Bureaucrat name : " << b.getName() << std::endl;
	// 	std::cout << "Bureaucrat grade : " << b.getGrade() << std::endl;
	// 	std::cout << b;
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	return (0);
}
