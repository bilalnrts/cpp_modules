#ifndef	ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *a, int lenght, void (*f)(T &))
{
	for (int i = 0; i < lenght; i++) {
		f(a[i]);
	}
}

template <typename T>
void	print(T &a)
{
	std::cout << a << std::endl;
}

#endif
