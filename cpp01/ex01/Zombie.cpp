#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this -> name = name;
}

Zombie::~Zombie()
{
	std::cout << this -> name << " is dead !" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this -> name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName() const
{
	return (this -> name);
}

void	Zombie::setName(std::string name)
{
	this -> name = name;
}
