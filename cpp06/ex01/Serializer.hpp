#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Mydata.hpp"
#include <iostream>

class Data;

class Serializer
{
	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &another);
		Serializer &operator=(const Serializer &another);

	public :
		static uintptr_t	serialize(Data *data);
		static Data			*deserialize(uintptr_t raw);
};

#endif
