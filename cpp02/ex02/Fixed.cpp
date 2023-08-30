#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &another)
{
	*this = another;
}

Fixed::Fixed(int const value)
{
	this -> _value = value << this -> _fixedvalue;
}

Fixed::Fixed(float const value)
{
	this -> _value = int(roundf(value * (1 << _fixedvalue)));;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &another)
{
	this -> _value = another.getRawBits();
	return *this;
}

bool	Fixed::operator<(const Fixed &another)
{
	return this -> _value < another.getRawBits();
}

bool	Fixed::operator>(const Fixed &another)
{
	return this -> _value > another.getRawBits();
}

bool	Fixed::operator<=(const Fixed &another)
{
	return this -> _value <= another.getRawBits();
}

bool	Fixed::operator>=(const Fixed &another)
{
	return this -> _value >= another.getRawBits();
}

bool	Fixed::operator==(const Fixed &another)
{
	return this -> _value == another.getRawBits();
}

bool	Fixed::operator!=(const Fixed &another)
{
	return this -> _value != another.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &another)
{
	Fixed result;

	result.setRawBits(this -> _value + another.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &another)
{
	Fixed result;

	result.setRawBits(this -> _value - another.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &another)
{
	Fixed result;

	result.setRawBits(this -> _value * another.getRawBits() >> this -> _fixedvalue);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &another)
{
	Fixed result;

	result.setRawBits(this -> _value / (another.getRawBits() >> this -> _fixedvalue));
	return (result);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this -> _value += 1;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this -> _value -= 1;
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this -> _value += 1;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this -> _value += 1;
	return (*this);
}

Fixed &Fixed::max(Fixed &o1, Fixed &o2)
{
	if (o1 > o2)
		return (o1);
	return (o2);
}

Fixed &Fixed::min(Fixed &o1, Fixed &o2)
{
	if (o1 > o2)
		return (o2);
	return (o1);
}

const Fixed &Fixed::max(const Fixed &o1, const Fixed &o2)
{
	if (o1.getRawBits() > o2.getRawBits())
		return(o1);
	return (o2);
}

const Fixed &Fixed::min(const Fixed &o1, const Fixed &o2)
{
	if (o1.getRawBits() > o2.getRawBits())
		return(o2);
	return (o1);
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
