#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int	_value;
		static const int	_fixedvalue = 8;
	public :
		Fixed(void);
		Fixed(const Fixed &another);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed&	operator=(const Fixed &another);
		bool	operator<(const Fixed &another);
		bool	operator>(const Fixed &another);
		bool	operator<=(const Fixed &another);
		bool	operator>=(const Fixed &another);
		bool	operator==(const Fixed &another);
		bool	operator!=(const Fixed &another);
		Fixed	operator+(const Fixed &another);
		Fixed	operator-(const Fixed &another);
		Fixed	operator*(const Fixed &another);
		Fixed	operator/(const Fixed &another);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		static	Fixed &max(Fixed &o1, Fixed &o2);
		static	Fixed &min(Fixed &o1, Fixed &o2);
		static const Fixed &max(const Fixed &o1, const Fixed &o2);
		static const Fixed &min(const Fixed &o1, const Fixed &o2);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream& output, const Fixed& fixed);

#endif
