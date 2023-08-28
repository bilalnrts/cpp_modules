#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int	_value;
		static const int	_fixedvale = 8;
	public :
		Fixed(void);
		Fixed(Fixed &another);
		~Fixed();
		Fixed& operator=(Fixed &another);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
