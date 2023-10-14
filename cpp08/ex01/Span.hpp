#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private :
		std::vector<int>	myList;
		unsigned int		size;

	public :
		Span(unsigned int n);
		~Span();
		Span(const Span &another);
		Span	&operator=(const Span &another);
		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

};

#endif
