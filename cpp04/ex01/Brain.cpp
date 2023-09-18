#include "Brain.hpp"
#include <random>

Brain::Brain()
{
	this -> ideas[0] = "I should eat something";
	this -> ideas[1] = "I should sleep";
	this -> ideas[2] = "I need some rest";
	this -> ideas[3] = "I need some rest";
	this -> ideas[4] = "I should drink water";
	this -> ideas[5] = "Should I run ?";
	this -> ideas[7] = "Am I in danger ?";
	this -> lastIdea = 8;
	std::cout << "(Brain) default constructor called !" << std::endl;
}

Brain::Brain(std::string newIdea)
{
	this -> ideas[0] = "I should eat something";
	this -> ideas[1] = "I should sleep";
	this -> ideas[2] = "I need some rest";
	this -> ideas[3] = "I need some rest";
	this -> ideas[4] = "I should drink water";
	this -> ideas[5] = "Should I run ?";
	this -> ideas[7] = "Am I in danger ?";
	this -> ideas[8] = newIdea;
	this -> lastIdea = 9;
	std::cout << "(Brain) string param constructor called !" << std::endl;
}

Brain::Brain(Brain &another)
{
	int i = 0;
	while (i < another.lastIdea)
	{
		this -> ideas[i] = another.ideas[i];
		i++;
	}
	this -> lastIdea = another.lastIdea;
	std::cout << "(Brain) copy constructor called !" << std::endl;
}

Brain::~Brain()
{
	std::cout << "(Brain) destructor called !" << std::endl;
}

Brain &Brain::operator=(Brain &another)
{
	if (this != &another)
		*this = another;
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index > this->lastIdea - 1)
		return (this -> ideas[this -> lastIdea - 1]);
	else if (index < 0)
		return (this->ideas[0]);
	else
		return (this->ideas[index]);
}
