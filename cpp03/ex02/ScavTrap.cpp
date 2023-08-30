#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap Constructor Called !" << std::endl;
	this -> _hitPoints = 100;
	this -> _attackDamage = 20;
	this -> _energy = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " was just born !" << std::endl;
	this -> _hitPoints = 100;
	this -> _attackDamage = 20;
	this -> _energy = 50;
}

ScavTrap::ScavTrap(ScavTrap &object)
{
	*this = object;
	std::cout << "ScavTrap copy constructor called ! " << this -> _name << " It has a twin now !" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &another)
{
	if (this == &another)
		return (*this);
	this -> _name = another._name;
	this -> _hitPoints = another._hitPoints;
	this -> _attackDamage = another._attackDamage;
	this -> _energy = another._energy;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this -> _name << " just disappeared !" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this -> _energy >= 1 && this -> _hitPoints >= 1)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this -> _attackDamage << " points of damage!" << std::endl;
		this -> _energy--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this -> _name << " has entered Gatekeeper mode !" << std::endl;
}
