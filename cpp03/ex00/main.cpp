#include "ClapTrap.hpp"

int main()
{
	ClapTrap bilal("Bilal");
	ClapTrap salih("Salih");
	ClapTrap emre("Emre");
	ClapTrap mustafa(salih);

	emre.attack("Salih");
	emre = bilal;
	emre.attack("Salih");

	bilal.attack("Emre");
	mustafa.attack("Oğuzhan");
	bilal.beRepaired(5);
	bilal.takeDamage(10);
	bilal.attack("Anıl");
	mustafa.takeDamage(10);
}
