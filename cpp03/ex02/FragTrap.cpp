#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called !" << std::endl;
	this -> _attackDamage = 30;
	this -> _energy = 100;
	this -> _hitPoints = 100;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " was just born !" << std::endl;
	this -> _attackDamage = 30;
	this -> _energy = 100;
	this -> _hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &another)
{
	*this = another;
	std::cout << "FragTrap copy constructor called ! " << this -> _name << " It has a twin now !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this -> _name << " just disappeared !" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &another)
{
	if (this == &another)
		return (*this);
	this -> _name = another._name;
	this -> _attackDamage = another._attackDamage;
	this -> _hitPoints = another._hitPoints;
	this -> _energy = another._energy;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this -> _energy >= 1 && this -> _hitPoints >= 1)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this -> _attackDamage << " points of damage!" << std::endl;
		this -> _energy--;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap (" << this -> _name << ") : High fives guys! Anyone? Please?" << std::endl;
}
