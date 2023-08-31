#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "(Animal) Default constructor called !" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "(Animal) \"" << type << "\" suddenly appeared !" << std::endl;
}

Animal::Animal(Animal &another)
{
	*this = another;
	std::cout << "(Animal) Copy constructor called !" << std::endl;
}

Animal &Animal::operator=(const Animal &another)
{
	if (this != &another)
		*this = another;
	return (*this);
}

Animal::~Animal()
{
	std::cout <<  "(Animal) " << this -> _type << " just disappeared !" << std::endl;
}

void	Animal::makeSound() const
{
}

std::string	Animal::getType() const
{
	return (this -> _type);
}
