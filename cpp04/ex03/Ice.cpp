#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &another) : AMateria(another)
{
}

Ice::~Ice()
{
	std::cout << "Ice destructor called !" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
