#include "easyfind.hpp"

int main() {
	std::vector<int> ar;
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	ar.push_back(4);
	ar.push_back(5);
	ar.push_back(6);
	ar.push_back(7);
	ar.push_back(8);
	ar.push_back(9);
	ar.push_back(10);

	try {
		int x = easyfind(ar, 4);
		int y = easyfind(ar, 9);
		std::cout << x << std::endl;
		std::cout << y << std::endl;

		int z = easyfind(ar, 15);
	} catch(std::exception &e) {
		std::cout << "There is no element in the container !" << std::endl;
	}

	return 0;
}
