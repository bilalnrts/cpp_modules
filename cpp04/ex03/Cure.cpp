#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &another) : AMateria(another)
{
}

Cure::~Cure()
{
	std::cout << "Cure destructor called !" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
