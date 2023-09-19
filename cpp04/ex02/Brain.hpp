#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private :
		int			lastIdea;

	public :
		std::string ideas[100];
		Brain();
		Brain(std::string newIdea);
		Brain(Brain &another);
		~Brain();
		Brain &operator=(Brain &another);
		std::string	getIdea(int index) const;
};

#endif
