#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "(Cat) Default constructor called !" << std::endl;
	this -> _type = "Cat";
}

Cat::Cat(std::string type)
{
	this -> _type = type;
	std::cout << "Cat \"" << type << "\" suddenly appeared !" << std::endl;
}

Cat::Cat(Cat &another)
{
	*this = another;
	std::cout << "(Cat) Copy constructor called ! " << std::endl;
}

Cat &Cat::operator=(const Cat &another)
{
	if (this == &another)
		this -> _type = another._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout <<  "Cat " << this -> _type << " just disappeared !" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
