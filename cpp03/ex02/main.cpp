#include "FragTrap.hpp"

int main()
{
	FragTrap bilal("Bilal");
	FragTrap salih("Salih");
	FragTrap nurtas(bilal);

	bilal.attack("Salih");
	salih.takeDamage(20);
	salih.beRepaired(25);
	nurtas = salih;
	nurtas.attack("Bilal");
	bilal.highFivesGuys();
	return (0);
}
