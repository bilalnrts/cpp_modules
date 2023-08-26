#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private :
		std::string type;
	public :
		Weapon(void);
		Weapon(std::string type);
		std::string getType(void) const;
		void		setType(std::string type);
};

#endif
