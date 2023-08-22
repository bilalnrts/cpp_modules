#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class PhoneBook {
	private:
		//Contact	_contacts[8]; -> This class will be created later
		int			_size;

	public:
		void		add();
		void		search();
		void		display();
		PhoneBook(void);
};

#endif
