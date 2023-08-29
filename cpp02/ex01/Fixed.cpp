#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &another)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = another;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this -> _value = value << this -> _fixedvalue;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this -> _value = int(roundf(value * (1 << _fixedvalue)));;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this -> _value = another.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	return (this -> _value);
}

void	Fixed::setRawBits(int const raw)
{
	this -> _value = raw;
}

float	Fixed::toFloat(void) const
{
	return float(this->_value) / (1 << _fixedvalue);
}

int	Fixed::toInt(void) const
{
	return this -> _value / 256;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return output;
}
