#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string target;
	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &another);
		ShrubberyCreationForm(const ShrubberyCreationForm &another);
		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
		class FormIsNotSigned : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

#endif
