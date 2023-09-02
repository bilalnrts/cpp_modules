#include "Character.hpp"

Character::Character(std::string const name) : _name(name), _size(0), _trashSize(0)
{
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this -> _inventory[i] != NULL)
			delete this -> _inventory[i];
	}
	if (this -> _trashSize)
	{
		for (int i = 0; i < this -> _trashSize; i++)
			delete _trash[i];
	}
	delete[] this->_trash;
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
		if (this -> _inventory[i] == NULL && ++this -> _size)
			this -> _inventory[i] = m;
	}
}

void Character::addTrash(AMateria *m)
{
	AMateria **newTrash = new AMateria *[this->_trashSize + 1];
	for (int i = 0; i < this->_trashSize; i++)
	{
		newTrash[i] = this->_trash[i];
	}
	newTrash[this->_trashSize] = m;
	delete[] this->_trash;
	this->_trash = newTrash;
	this->_trashSize++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this -> _inventory[idx] == NULL)
		return ;
	addTrash(this -> _inventory[idx]);
	this -> _inventory[idx] = NULL;
	--this -> _size;
}

void	Character::use(int idx, ICharacter &target)
{
	if (&target == NULL || idx < 0 || idx > 3 || this -> _inventory[idx] == NULL)
		return ;
	this -> _inventory[idx]->use(target);
}
