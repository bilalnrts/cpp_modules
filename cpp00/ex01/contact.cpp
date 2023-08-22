#include "contact.hpp"

void	Contact::setName(std::string name)
{
	this -> _name = name;
}

void	Contact::setSurname(std::string surname)
{
	this -> _surname = surname;
}

void	Contact::setNickname(std::string nickname)
{
	this -> _nick = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this -> _phoneNumber = phoneNumber;
}

void	Contact::setSecret(std::string secret)
{
	this -> _secret = secret;
}

std::string	Contact::getName() const
{
	return (this -> _name);
}

std::string	Contact::getSurname() const
{
	return (this -> _surname);
}

std::string	Contact::getNickname() const
{
	return (this -> _nick);
}

std::string	Contact::getPhoneNumber() const
{
	return (this -> _phoneNumber);
}

std::string	Contact::getSecret() const
{
	return (this -> _secret);
}
