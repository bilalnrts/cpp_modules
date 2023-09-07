#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	protected :
		std::string const	_name; //must be const
		int					_grade;
	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &another);
		Bureaucrat &operator=(const Bureaucrat &another);
		~Bureaucrat();
		const std::string	getName(void) const;
		int 				getGrade(void) const;
		void				increment(void);
		void				decrement(void);
		void				signForm(AForm &f);
		void				executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif
