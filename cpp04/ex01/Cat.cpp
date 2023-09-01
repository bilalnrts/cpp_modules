#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "(Cat) Default constructor called !" << std::endl;
	this -> _type = "Cat";
	this -> _catBrain = new Brain();
}

Cat::Cat(std::string type)
{
	this -> _type = type;
	this -> _catBrain = new Brain();
	std::cout << "Cat \"" << type << "\" suddenly appeared !" << std::endl;
}

Cat::Cat(const Cat &another)
{
	this -> _catBrain = new Brain(*another._catBrain);
	std::cout << "(Cat) Copy constructor called ! " << std::endl;
}

Cat &Cat::operator=(const Cat &another)
{
	if (this != &another)
	{
		this -> _type = another._type;
		delete this -> _catBrain;
		this -> _catBrain = new Brain(*another._catBrain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _catBrain;
	std::cout <<  "(Cat) " << this -> _type << " just disappeared !" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain &Cat::getBrain() const
{
	return (*_catBrain);
}
