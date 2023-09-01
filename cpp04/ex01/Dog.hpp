#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain *_dogBrain;
	public :
		Dog();
		Dog(std::string type);
		Dog(Dog &another);
		Dog &operator=(const Dog &another);
		~Dog();
		void	makeSound(void) const;
		Brain &getBrain(void) const;
};

#endif
