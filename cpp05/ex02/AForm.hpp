#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public :
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &another);
		AForm &operator=(const AForm &another);
		virtual ~AForm();
		const std::string	getName(void) const;
		int const			getGradeToSign(void) const;
		int const			getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat const &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif
