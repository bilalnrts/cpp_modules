#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	return ;
}

AMateria::AMateria(const AMateria &another) : _type(another._type)
{
	return ;
}

AMateria::~AMateria()
{
	std::cout << "zaaaa xd" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this -> _type);
}
