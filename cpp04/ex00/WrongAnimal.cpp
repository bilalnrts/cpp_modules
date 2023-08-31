#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "(WrongAnimal) Default constructor called !" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "(WrongAnimal) \"" << type << "\" was just appeared !" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &another)
{
	*this = another;
	std::cout << "(WrongAnimal) copy constructor called !" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "(WrongAnimal) \"" << this -> _type << "\" just disappeared !" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &another)
{
	if (this != &another)
		*this = another;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound !" << std::endl;
}
