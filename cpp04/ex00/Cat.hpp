#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(std::string type);
		Cat(Cat &another);
		Cat &operator=(const Cat &another);
		~Cat();
		void	makeSound(void) const;
};

#endif
