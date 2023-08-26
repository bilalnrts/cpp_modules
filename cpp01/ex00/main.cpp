#include "Zombie.hpp"

int main()
{
	Zombie normalZombie("normalZombie");
	Zombie *ptrZombie = newZombie("ptrZombie");
	normalZombie.announce();
	ptrZombie -> announce();
	randomChump("normalZombie2");
	delete ptrZombie;
	return (0);
}
