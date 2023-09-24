#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute): name(name), gradeSign(gradeSign), gradeExecute(gradeExecute), isSigned(false)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw(Form::GradeTooLowException());
	else if (gradeSign < 1 || gradeExecute < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form()
{
}

Form::Form(const Form &another): name(another.getName()), gradeSign(another.getGradeSign()), gradeExecute(another.getGradeExecute())
{
	*this = another;
}

Form &Form::operator=(const Form &another)
{
	if (this != &another)
		this->isSigned = another.getIsSigned();
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeSign() const
{
	return (this -> gradeSign);
}

int	Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("GRADE TOO LOW !");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("GRADE TOO HIGH !");
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
	o << "Name : " + f.getName() << std::endl;
	o << "Is signed : " << f.getIsSigned() << std::endl;
	o << "Form grade to sign " << f.getGradeSign() << std::endl;
	o << "Form grade to execute " << f.getGradeExecute() << std::endl;
	return (o);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->gradeSign)
		this->isSigned = true;
	else
		throw (Form::GradeTooLowException());
}
