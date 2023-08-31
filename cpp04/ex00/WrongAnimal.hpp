#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
		std::string	_type;
	public :
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal &another);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal &another);
		void	makeSound(void) const;
};

#endif
