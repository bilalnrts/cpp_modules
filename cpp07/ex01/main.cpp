#include "iter.hpp"

int main( void ) {
	//----CASE 1----
	int array[5] = {1, 2, 3, 4, 5};
	iter(array, 5, print);

	//----CASE 2----
	// std::string array[5] = {"String 1", "String 2", "String 3", "String 4", "String 5"};
	// iter (array, 5, print);

	return (0);
}
