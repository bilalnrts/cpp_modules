#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria &another) : _type(another._type)
{
}

AMateria::~AMateria()
{
	std::cout << "(" << this -> _type << ") AMateria destructor called !" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this -> _type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
