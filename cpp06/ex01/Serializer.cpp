#include "Mydata.hpp"
#include "Serializer.hpp"

// Data
Data::Data(int	value): value(value) {}
Data::Data(const Data &another) {*this = another;}
Data	&Data::operator=(const Data &another)
{
	this->value = another.value;
	return (*this);
}
Data::~Data() {}

//Serializer
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &another) {}
Serializer	&Serializer::operator=(const Serializer &another) {return (*this);}
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
