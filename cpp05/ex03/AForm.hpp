#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public :
		AForm(std::string name, int gradeSign, int gradeExecute);
		virtual ~AForm();
		AForm(const AForm &another);
		AForm &operator=(const AForm &another);
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;
		void		beSigned(const Bureaucrat &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;
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

std::ostream &operator<<(std::ostream &o, AForm &f);


#endif
