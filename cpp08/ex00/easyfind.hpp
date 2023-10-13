#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int	easyfind(T &a, int b)
{
	typename T::iterator ptr;
	for (ptr = a.begin(); ptr != a.end(); ptr++) {
		if (*ptr == b)
			return (b);
	}
	throw std::exception();
}

#endif
