#include "phonebook.hpp"

int	main()
{
	std::string	input;
	int			index;
	PhoneBook	phoneBook;

	while (input != "EXIT")
	{
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
		{
			phoneBook.display();
			std::cout << "Please enter the index of the contact" << std::endl;
			std::getline(std::cin, input);
			index = strtol(input.c_str(), NULL, 10);
			while (index <= 0 || index > phoneBook.get_size())
			{
				std::cout << "Index does not match!" << std::endl;
				std::getline(std::cin, input);
				index = strtol(input.c_str(), NULL, 10);
			}
			phoneBook.search(index);
		}
		std::cout << "Enter the command -> ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
	}
	return (0);
}
