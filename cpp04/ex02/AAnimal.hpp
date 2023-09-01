#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected :
		std::string	_type;
	public :
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal &another);
		AAnimal &operator=(const AAnimal &another);
		virtual ~AAnimal();
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
