#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public :
		Form(std::string name, int gradeSign, int gradeExecute);
		~Form();
		Form(const Form &another);
		Form &operator=(const Form &another);
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;
		void		beSigned(const Bureaucrat &b);
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form &f);


#endif
