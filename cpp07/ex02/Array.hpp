#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private :
		T				*array;
		unsigned int	lenght;

	public :
		Array() { array = new T[0]; lenght = 0;}
		Array(unsigned int n) { array = new T[n]; lenght = n;}
		Array(const Array &another)
		{
			lenght = another.lenght;
			array = new T[lenght];
			for (unsigned int i = 0; i < lenght; i++) {
				array[i] = another.array[i];
			}
		}
		~Array() {delete[] array;}
		Array & operator=(const Array &another)
		{
			if (this != &another)
			{
				delete[] array;
				lenght = another.lenght;
				array = new T[lenght];
				for (int i = 0; i < lenght; i++) {
					array[i] = another.array[i];
				}
			}
		}
		T	&operator[](unsigned int i) const
		{
			if (i >= lenght)
				throw std::exception();
			return (array[i]);
		}
		unsigned int size() const
		{
			return (lenght);
		}
};

#endif
