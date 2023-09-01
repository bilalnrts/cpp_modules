#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *_catBrain;
	public :
		Cat();
		Cat(std::string type);
		Cat(const Cat &another);
		Cat &operator=(const Cat &another);
		~Cat();
		void	makeSound(void) const;
		Brain &getBrain(void) const;
};

#endif
