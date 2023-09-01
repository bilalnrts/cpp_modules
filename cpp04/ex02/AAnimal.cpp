#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown")
{
	std::cout << "(AAnimal) Default constructor called !" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "(AAnimal) \"" << type << "\" suddenly appeared !" << std::endl;
}

AAnimal::AAnimal(AAnimal &another)
{
	*this = another;
	std::cout << "(AAnimal) Copy constructor called !" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &another)
{
	if (this != &another)
		*this = another;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout <<  "(AAnimal) " << this -> _type << " just disappeared !" << std::endl;
}

void	AAnimal::makeSound() const
{
}

std::string	AAnimal::getType() const
{
	return (this -> _type);
}
