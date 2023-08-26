#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(3, "Bilal");
	for (int i = 0; i < 3; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

	//system("leaks zombiehorde");
	return (0);
}
