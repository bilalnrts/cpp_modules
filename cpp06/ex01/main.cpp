#include "Serializer.hpp"

int main()
{
	Data	data(42);
	Data	*dataPtr = &data;
	uintptr_t	sPtr = Serializer::serialize(dataPtr);
	Data		*desPtr = Serializer::deserialize(sPtr);
	if (desPtr == dataPtr) {
		std::cout << "Serialization and deserialization successfully done !" << std::endl;
	} else {
		std::cout << "Fail !" << std::endl;
	}
}
