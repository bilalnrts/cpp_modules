#include "Span.hpp"

int main()
{
    // ----CASE 1----
    Span sp = Span(5);
    sp.addNumber(3);
    sp.addNumber(6);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return (0);
    // ----CASE 2----
    // try
	// {
	// 	Span span(10000);
	// 	for (int i = 0; i <= 9999; i++)
	// 		span.addNumber(i);
	// 	std::cout << span.shortestSpan() << std::endl;
	// 	std::cout << span.longestSpan() << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}