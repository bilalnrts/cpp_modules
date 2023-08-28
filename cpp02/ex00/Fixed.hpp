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
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
