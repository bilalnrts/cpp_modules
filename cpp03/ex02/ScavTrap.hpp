#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(ScavTrap &object);
		ScavTrap &operator=(const ScavTrap &another);
		~ScavTrap();
		void	attack(const std::string &target);
		void	guardGate();
};

#endif
