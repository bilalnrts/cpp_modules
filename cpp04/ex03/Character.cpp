#include "Character.hpp"

Character::Character(std::string const name) : _name(name), _size(0)
{
	for (int i = 0; i < 4; i++) {
		this -> _inventory[i] = NULL;
	}
}

Character::Character(const Character &another) : _name(another._name), _size(another._size)
{
	for (int i = 0; i < 4; i++)
	{
		if (another._inventory[i])
			this -> _inventory[i] = another._inventory[i]->clone();
		else
			this -> _inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &another)
{
	if (this == &another)
		return (*this);
	this -> ~Character();
	for (int i = 0; i < 4; i++)
	{
		if (another._inventory[i])
			this -> _inventory[i] = another._inventory[i]->clone();
		else
			this -> _inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this -> _inventory[i])
			delete this -> _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this -> _name);
}

void	Character::equip(AMateria *m)
{
	if (this -> _size == 4 || !m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this -> _inventory[i] == m)
			break ;
		if (this -> _inventory[i] == NULL)
		{
			this -> _inventory[i] = m;
			this -> _size++;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this -> _inventory[idx] == NULL)
		return ;
	this -> _inventory[idx] = NULL;
	--this -> _size;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this -> _inventory[idx] == NULL)
		return ;
	this -> _inventory[idx]->use(target);
}
