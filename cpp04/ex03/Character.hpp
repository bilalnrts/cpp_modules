#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	protected :
		std::string			_name;
		AMateria			*_inventory[4];
		int					_size;

	public :
		Character(std::string name);
		Character(const Character &another);
		Character &operator=(const Character &another);
		~Character();
		std::string const &getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif
