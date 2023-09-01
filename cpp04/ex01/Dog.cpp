#include "Dog.hpp"

Dog::Dog()
{
	this -> _type = "Dog";
	this -> _dogBrain = new Brain();
	std::cout << "(Dog) Default constructor called !" << std::endl;
}

Dog::Dog(std::string type)
{
	this -> _type = type;
	this -> _dogBrain = new Brain();
	std::cout << "Dog \"" << type << "\" suddenly appeared !" << std::endl;
}

Dog::Dog(Dog &another)
{
	this -> _dogBrain = new Brain(*another._dogBrain);
	std::cout << "(Dog) Copy constructor called !" << std::endl;
}

Dog &Dog::operator=(const Dog &another)
{
	if (this != &another)
	{
		this -> _type = another._type;
		delete this -> _dogBrain;
		this -> _dogBrain = new Brain(*another._dogBrain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "(Dog) " << this -> _type << " just disappeared !" << std::endl;
	delete this -> _dogBrain;
}

void	Dog::makeSound() const
{
	std::cout << "Hav!" << std::endl;
}

Brain &Dog::getBrain() const
{
	return (*_dogBrain);
}
