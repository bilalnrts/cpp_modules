#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private :
		std::string	_name;
		int			_hitPoints;
		int			_energy;
		int			_attackDamage;

	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &object);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &another);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
