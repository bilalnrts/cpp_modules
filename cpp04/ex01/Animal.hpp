#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string	_type;
	public :
		Animal();
		Animal(std::string type);
		Animal(Animal &another);
		Animal &operator=(const Animal &another);
		virtual ~Animal();
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
