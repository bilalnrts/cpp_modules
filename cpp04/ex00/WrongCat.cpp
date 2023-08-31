#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this -> _type = "Cat";
	std::cout << "(WrongCat) Default constructor called !" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this -> _type = type;
	std::cout << "(WrongCat) \"" << type << "\" was just appeared!" << std::endl;
}

WrongCat::WrongCat(WrongCat &another)
{
	*this = another;
	std::cout << "(WrongCat) Copy constructor called !" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &another)
{
	if (this != &another)
		*this = another;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "(WrongCat) Meow!" << std::endl;
}
