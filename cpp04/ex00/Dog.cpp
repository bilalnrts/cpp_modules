#include "Dog.hpp"

Dog::Dog()
{
	this -> _type = "Dog";
	std::cout << "(Dog) Default constructor called !" << std::endl;
}

Dog::Dog(std::string type)
{
	this -> _type = type;
	std::cout << "Dog \"" << type << "\" suddenly appeared !" << std::endl;
}

Dog::Dog(Dog &another)
{
	*this = another;
	std::cout << "(Dog) Copy constructor called !" << std::endl;
}

Dog &Dog::operator=(const Dog &another)
{
	if (this != &another)
		this -> _type = another._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog " << this -> _type << " just disappeared !" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Hav!" << std::endl;
}
