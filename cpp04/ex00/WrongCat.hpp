#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat &another);
		~WrongCat();
		WrongCat &operator=(WrongCat &another);
		void	makeSound(void) const;
};

#endif
