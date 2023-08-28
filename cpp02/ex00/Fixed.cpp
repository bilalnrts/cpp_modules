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
