#include "phonebook.hpp"

PhoneBook::PhoneBook(void): _size(0)
{

}

std::string	PhoneBook::get_input(std::string str)
{
	std::string input;

	while (input.empty())
	{
		std::cout << str;
		std::getline(std::cin, input);
	}
	return (input);
}

void	PhoneBook::add()
{
	_contacts[_moment].setName(get_input("First name : "));
	_contacts[_moment].setSurname(get_input("Last name : "));
	_contacts[_moment].setNickname(get_input("Nickname : "));
	_contacts[_moment].setPhoneNumber(get_input("Phone Number : "));
	_contacts[_moment].setSecret(get_input("Dark secret : "));
	_moment = (_moment + 1) % 8;
	if (this -> _size < 8)
		this -> _size++;
}

void	print_for_lenght(std::string str)
{
	int	len;
	int	space;

	len = str.length();
	if (len <= 10)
	{
		space = 10 - len + 1;
		while (--space)
			std::cout << " ";
		std::cout << str;
	}
	else
		std::cout << str.substr(0, 9) << ".";
}

void	PhoneBook::display()
{
	int	i;

	i = 0;
	while (i < _size)
	{
		std::cout << i + 1 << "|";
		print_for_lenght(_contacts[i].getName());
		std::cout << "|";
		print_for_lenght(_contacts[i].getSurname());
		std::cout << "|";
		print_for_lenght(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
}

void	PhoneBook::search(int id)
{
	if (id > 0 && id <= _size)
	{
		std::cout << "First name : " << _contacts[id - 1].getName() << std::endl;
		std::cout << "Last name : " << _contacts[id - 1].getSurname() << std::endl;
		std::cout << "Nickname : " << _contacts[id - 1].getNickname() << std::endl;
		std::cout << "Phone Number : " << _contacts[id - 1].getPhoneNumber() << std::endl;
		std::cout << "Dark secret : " << _contacts[id - 1].getSecret() << std::endl;
	}
}

int	PhoneBook::get_size() const
{
	return (this -> _size);
}
