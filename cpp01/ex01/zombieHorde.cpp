#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombieArray = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		zombieArray[i].setName(std::to_string(i + 1) + ". " + name);
		i++;
	}
	return (zombieArray);
}
