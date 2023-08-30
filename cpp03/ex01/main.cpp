#include "ScavTrap.hpp"

int main()
{
	ScavTrap bilal("Bilal");
	ScavTrap salih("Salih");
	ScavTrap nurtas(bilal);

	bilal.attack("Salih");
	salih.takeDamage(20);
	salih.beRepaired(25);
	nurtas = salih;
	nurtas.attack("Bilal");
	return (0);
}
