#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energy(10), _attackDamage(0)
{
	std::cout << "(Default Cons) ClapTrap Default was just born !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " was just born !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &object)
{
	*this = object;
	std::cout << "Copy constructor called ! " << this -> _name << " It has a twin now !" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &another)
{
	this -> _name = another._name;
	this -> _hitPoints = another._hitPoints;
	this -> _energy = another._energy;
	this -> _attackDamage = another._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this -> _name << " just disappeared !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this -> _energy >= 1 && this -> _hitPoints >= 1)
	{
		this -> _hitPoints = (this -> _hitPoints + amount > 10) ? 10 : this -> _hitPoints + amount;
		this -> _energy--;
		std::cout << "ClapTrap " << this -> _name << " repaired itself (" << amount << ") !" << " It has " << this -> _hitPoints << " hit points now !" << std::endl;
	}
}

void	ClapTrap::attack(const std::string &target)
{
	if (this -> _energy >= 1 && this -> _hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this -> _attackDamage << " points of damage!" << std::endl;
		this -> _energy--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this -> _hitPoints == 0)
	{
		std::cout << "ClapTrap " << this -> _name << " is already dead. Let him rest in peace!" << std::endl;
		std::cout << "Poor ClapTrap " << this -> _name << " took " << amount << " damage while dead. :(" << std::endl;
	}
	else
	{
		if (amount >= this -> _hitPoints)
		{
			std::cout << "ClapTrap " << this -> _name << " took " << amount << " damage and died ! Rip " << this -> _name << std::endl;
			this -> _hitPoints = 0;
		}
		else
		{
			this -> _hitPoints -= amount;
			std::cout << "ClapTrap " << this -> _name << "took " << amount << " damage !" << " It has " << this -> _hitPoints << " hit points now !" << std::endl;
		}
	}
}
