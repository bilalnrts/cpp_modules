#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(std::string type);
		Dog(Dog &another);
		Dog &operator=(const Dog &another);
		~Dog();
		void	makeSound(void) const;
};

#endif
