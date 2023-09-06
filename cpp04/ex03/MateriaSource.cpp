#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this -> _invertory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this -> _invertory[i])
			delete this -> _invertory[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this -> _invertory[i])
		{
			this -> _invertory[i] = materia -> clone();
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this -> _invertory[i]->getType() == type)
			return (this -> _invertory[i]->clone());
	}
	return (0);
}
