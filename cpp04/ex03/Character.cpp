#include "Character.hpp"

Character::Character(std::string const name) : _name(name), _size(0), _trashSize(0)
{
	for (int i = 0; i < 4; i++) {
		this -> _inventory[i] = NULL;
	}
}

Character::~Character()
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this -> _inventory[i])
	// 	{
	// 		std::cout << i << std::endl;
	// 		delete this -> _inventory[i];
	// 	}
	// }
	// if (this -> _trashSize)
	// {
	// 	for (int i = 0; i < this -> _trashSize; i++)
	// 		delete _trash[i];
	// }
	delete[] this->_trash;
	std::cout << this -> getName() << " (Character) destructor called !" << std::endl;
}

std::string const &Character::getName() const
{
	return (this -> _name);
}

void	Character::listMat()
{
	std::cout << "0 : " << this -> _inventory[0]->getType() << std::endl;
	std::cout << "1 : " << this -> _inventory[1]->getType() << std::endl;
	std::cout << "2 : " << this -> _inventory[2]->getType() << std::endl;
	std::cout << "3 : " << this -> _inventory[3]->getType() << std::endl;
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
	if (idx < 0 || idx > 3 || this -> _inventory[idx] == NULL)
		return ;
	this -> _inventory[idx]->use(target);
}
