#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public :
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const &another);
		Form &operator=(const Form &another);
		~Form();
		const std::string	getName(void) const;
		int const			getGradeToSign(void) const;
		int const			getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat const &b);
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

std::ostream &operator<<(std::ostream &o, Form &f);

#endif
