#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		const std::string	name;
		int					grade;

	public :
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &another);
		Bureaucrat &operator=(const Bureaucrat &another);
		std::string getName() const;
		int			getGrade() const;
		int			increment();
		int			decrement();
		void		signForm(Form &f);
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif
