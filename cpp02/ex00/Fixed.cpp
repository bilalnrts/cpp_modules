#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(Fixed &another)
{
	*this = another;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this -> _value = another.getRawBits();
}
